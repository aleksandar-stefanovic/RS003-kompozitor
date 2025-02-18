# RS003-kompozitor

## Team Members
* Aleksandar Stefanović &emsp;mi17479@alas.matf.bg.ac.rs
* Kristina Pantelić&emsp;&emsp;&emsp;&emsp;mi16091@alas.matf.bg.ac.rs
* Anđelka Milovanović&emsp;&emsp;mi15145@alas.matf.bg.ac.rs

## Appearance
![current_state](https://github.com/MATF-RS20/RS003-kompozitor/blob/master/wiki/week5_state.png)

## Short Description
Kompozitor is a course project with a goal of exercising good development practices and design patterns in a team environment.<br>
It features creating synthetic sounds (by generating sine waves of various frequencies) using a keyboard-like interface, as well as combining it with microphone audio recordings.<br>

### Libraries used
* Qt5 for the GUI, using QML as the "View" part of MVVM
* SFML for recording and reproducing sound

#### Running the project in CLion
To run the project in the CLion IDE, you need to go to: `Settings > Build, Execution, Deployment > CMake` and set **CMake options** to:
```
-DCMAKE_PREFIX_PATH=/PATH/TO/YOUR/Qt/5.12.6/gcc_64/lib/cmake/
```
The usual path for Unix systems is:
```
-DCMAKE_PREFIX_PATH=~/Qt/5.12.6/gcc_64/lib/cmake/
``` 

#### Running the project from the terminal
1. **`cmake`** needs to be present on the system
2. **`git clone https://github.com/MATF-RS20/RS003-kompozitor.git`**
4. Create **_build_** directory in _**RS003-kompozitor**_
5. Move to _**build**_ directory and run the command: <br>
**`cmake .. -DCMAKE_PREFIX_PATH=~/Qt/5.13.2/clang_64/lib/cmake`** (or a different path for your setup)
6. Run **`make`** 
7. Run the executable with: **`./Kompozitor`**
