# Geant4 Detector Construction Pattern (G4DCP)

G4DCP is a new detector construction strategy for creating flexible detector setups in Geant4 applications. The elements of G4DCP, in conjunction with G4VUserDetectorConstruction, the abstract class provided by Geant4, constitute an elegant template for detector setups. 
 ![g4dcp](https://github.com/mkandemirr/G4DCP/assets/114905224/cd4af645-a8aa-40ba-93e8-dcf014909077)
##
##

## The package structure:  


_g4dcp/g4dcp_: This directory includes two class templates that are used to generate builder classes for G4Material, G4LogicalVolume and G4VPhysicalVolume. 

_g4dcp/example_: This directory contains a sample Geant4 application that shows how to create a detector using G4DCP.

## Tested on 

* Os: Linux (Ubuntu 22.04.2 LTS)
* Architecture: x86_64
* Compiler: GCC 11.3.0
* Geant4.11.1.1

## How to run the provided example application?   
  
1. Go to the directory where you installed the example in your system.
  ```bash	
   cd path/To/example
  ```
  
2. Create a directory named example-build in the same directory as example. 
  ```bash
   mkdir example-build
   ```

3. Now go inside this build directory and run CMake to generate the Makefiles needed to build the application. Two arguments are 
passed to CMake. The first argument to CMake is the path to the source directory that includes the CMakeList.txt file. The second argument is the path to the build directory where the generated make files will be located. CMake will now run to configure the build and generate Makefiles.
```bash
  cd example-build
  cmake -S ../example -B .
 ```
5. With the Makefile available, you can now build by simply running make: 
  ```bash
   make  
  ```
5. The application is now ready to run. If you now list the contents of your build directory, you will notice that the executable g4dcp has been created. The program can be executed in two modes: interactive and batch. To run in an interactive mode:
  ```bash
   ./g4dcp
``` 
## Contacts 

If you have any questions or wish to notify of updates and/or modification please contact: \
Mustafa Kandemir (mustafa.kandemir@erdogan.edu.tr)

