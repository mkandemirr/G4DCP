# Geant4 Detector Construction Pattern (G4DCP)
G4DCP is a new detector construction interface for creating flexible detector setups in Geant4 applications. The elements of G4DCP, including G4VUserDetectorConstruction, form an elegant template for detector setups. The figure below summarizes the structure of G4DCP in a UML diagram.
<br>
<br>
 ![g4dcp](https://github.com/mkandemirr/G4DCP/assets/114905224/cd4af645-a8aa-40ba-93e8-dcf014909077)
<br>
<br>
The following code sample shows examples of creating concrete component builder and component factory classes using the elements of G4DCP.
```cpp
//Only relevant sections are displayed.
//Creating a concrete logical volume builder class
class UserLVBuilder : public VComponentBuilder<G4LogicalVolume> {
	protected:  
    virtual G4LogicalVolume* Build() override;
};
G4LogicalVolume* UserLVBuilder::Build()
{
//Implementation..
}
//Creating a concrete physical volume builder class
class UserPVBuilder : public VComponentBuilder<G4VPhysicalVolume> {
	protected:  
    virtual G4VPhysicalVolume* Build() override;
};
G4VPhysicalVolume* UserPVBuilder::Build()
{
//Implementation..
}
//Creating a concrete material builder class
class UserMaterialBuilder : public VComponentBuilder<G4Material> {
	protected:  
    virtual G4Material* Build() override;
};
G4Material* UserMaterialBuilder::Build()
{
//Implementation..
}
//Creating a concrete logical volume factory class. This class can be made singleton.
class UserLogicalVolumeFactory: public VComponentFactory<G4LogicalVolume>
{       
  protected:    
    virtual G4LogicalVolume* Create(const G4String& name) override;             
};
G4LogicalVolume* UserLogicalVolumeFactory::Create(const G4String& name)
{
	G4LogicalVolume* lv = G4LogicalVolumeStore::GetInstance()->GetVolume(name);
  if(lv) return lv;

  if(name=="")
  {
  	UserLVBuilder1 builder;
  	return builder.GetProduct();
   
  }else if(name=="")
  {
  	UserLVBuilder2 builder;
  	return builder.GetProduct();
  }
  .
  .
  .
  else 
  {
    return nullptr; //the Get() method in the parent class handle nullptr (look at Fig. 1).
  }
   
}
//Getting desired component object from the user detector construction class.
class UserDetectorConstruction : public G4VUserDetectorConstruction{
  G4VPhysicalVolume* Construct() override;
};
G4VPhysicalVolume* DetectorConstruction::Construct()
{
  //G4VPhysicalVolume* pv = UserPhysicalVolumeFactory::GetInstance()->Get("..");	
  //G4LogicalVolume* pv = UserLogicalVolumeFactory::GetInstance()->Get("..");	
  UserLVBuilder1 builder;
  G4LogicalVolume* lv = builder.GetProduct();
  //code for final detector construction 
}
```

## The package structure:  
_g4dcp/g4dcp_: This directory includes two class templates that are used to generate builder classes related to geometry such as G4Material, G4LogicalVolume, G4VPhysicalVolume, G4OpticalSurface and so on. 
_g4dcp/example_: This directory contains a sample Geant4 application that shows how to construct a detector using G4DCP.

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

