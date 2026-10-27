# Concert Venue

**Name:** Jason Bahati · **Section:** CSCI 1260-002  

**Language:** C++  

**World:** A concert venue that books rock bands, jazz ensembles, and DJs, runs sound checks through its PA system, and keeps a record of past performances.

## How to run
from Repo root:
```
cmake -S . -B build && cmake --build build && ./build/app
```
Or, after the first configure, cmake --build build --target run.
Run it from the repository root: the program reads data.txt and writes soundboard_log.txt there. It takes no keyboard input and runs from start to finish

CODE REVIEW:

UML DIAGRAM:

## Design questions

### 1. Two Diamonds
**Aggregation, `Venue` ◇ `Act`.** `main` creates every act with `new` (for example `new RockBand("The Strokes", 5, 4)`) and passes the pointer to `Venue::Add`, which only stores it in its `vector<Act*>`. The venue never creates or deletes an act. When a venue is removed, the acts keep existing: the program shows this with a Rooftop Pop-Up venue that books Skrillex and is destroyed at its closing brace, after which Skrillex is printed again. `main` deletes the acts at the end. If `Venue::Add` took a name and called `new` itself, and `Venue`'s destructor deleted its acts, the venue would own them and this would become composition.

**Composition, `Act` ◆ `SetList`.** `Act::AddSong` creates every `SetList` itself (`SetList s(nextSeq, title, minutes);`); `main` only passes a title and a length. The songs are stored by value in a `vector<SetList>` that is a private member of the act, and no method hands that vector out (`SetlistLines()` returns a string). When an act is deleted, its songs are destroyed with it. If `AddSong` accepted a `SetList*` that `main` had created, the songs would exist on their own and this would become aggregation.

### 2. The interface

`IAmplified` is signed by `RockBand` (under `Band`) and `DJ` (directly under `Act`). Those two do not share a parent below the root, so the only class that could hold the methods instead is `Act`. They can't go on `Act` because `JazzBand` plays acoustic: it has no wattage and no rig to plug in, so it would have to return a made-up number from `WattsRequired()`. Keeping the promise on an interface means only the acts that really use the PA make it. `SoundEngineer::Prepare(IAmplified&)` only needs those two methods, so it works with The Strokes, Pink Floyd, and Skrillex without knowing which kind of act each one is.

### 3. Adding a new kind

To add an `Orchestra` under `Band`, I would create `include/Orchestra.h` and `src/Orchestra.cpp`. I would edit `include/AllHeaderFiles.h` to include the new header, `src/main.cpp` to create an orchestra and add it to the venue and the lineup, and `docs/uml.png` to add the class. `Venue` does not change, because it only works with `Act*` and never names a concrete class. `CMakeLists.txt` does not change either, because it picks up every `.cpp` in `src/` automatically. The polymorphic loop and the sound check loop stay the same: the orchestra's own `Describe()` runs, and the `dynamic_cast` finds no `IAmplified` on it, so it is reported as acoustic.
