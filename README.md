# Build workflow
The build workflow for R2D2-2019 is based on the BMPTK (bare metal programming tool kit) made by Wouter van Ooijen. This guide will help you install and work with this environment.

## Installation
 
 ### Windows:

 1. Install git by visiting the git [download](https://git-scm.com/download/win) page.  Install using all the default settings and make sure the checkbox which adds git to your path is checked. **note:** If you already installed git on your machine you can skip this step.
 2. Pull the build repo by typing `git clone "add link here"` you can clone repo to whatever drive or folder you want. Remember the path you cloned the repo to.
 3. Open windows explorer and go to the place you cloned the repo, browse to the folder `R2D2-build/programs/install`
 4. Double-click on the "mingw-w64-install.exe" after the installation wizard has opened click next until you can select the installation path at this point change the path to the following `<path-to-your-repo>/R2D2-build/programs`. Install by clicking next. After installation a folder `mingw32` should have appeared int the `R2D2-build/programs` directory.
 5.  Double-click on the "gcc-arm-none-eabi-8-2018-q4-major-win32-sha1.exe" after the installation wizard has opened click next until you can select the installation path at this point change the path to the following `<path-to-your-repo>/R2D2-build/programs`. Install by clicking next. After installation a folder `8 2018-q4-major` should have appeared int the `R2D2-build/programs` directory.
 6. Return to the main directory of the repository and run the "init.bat" file. **note:** this file needs to be run as administrator and add all the necessary components to the path environment variable. If you prefer to do this manually you are welcome to do so. The most important path to add is the following `<path-to-your-repo>/R2D2-build/programs/bmptk/tools`
 7. Check if everything is working by opening a command prompt en typ `bmptk-make` if the console returns something like this `bmptk-make: *** no targets specified and no makefiles found. Stop.` everything should work fine.

**Warning:** This installation replaces earlier installations of BMPTK make sure to remove old installation from your PATH environment variable's. 


### creating a new module:
1. Open windows explorer.
2. Browse to the following directory `<path-to-your-repo>/R2D2-build/modules`
3. Create a new folder with the name of your module. **note:** Keep in mind the style guide rules. A name could be "test_module"
4. copy the contents of the template-arduino or template-native directory to the folder of your module. **note:** native projects are for running on your pc and arduino for flashing to the due.

### Writing code:

 1. In the folder of your module that you just created there is a folder named "code" go to this directory.
 2. The "main.cpp" will remain in this directory
 3. .hpp files need to be located in the "headers" folder
 4. .cpp files need to be located in the "src" folder.

### Building a project:

 1. Open a command prompt 
 2. Use cd command to go to the directory `<path-to-your-repo>/R2D2-build/modules/<name-of-your-module>/code`
 3. In this directory run the following command `bmptk-make build`

 ### Flashing or running a project:

 1. Open a command prompt 
 2. Use cd command to go to the directory `<path-to-your-repo>/R2D2-build/modules/<name-of-your-module>/code`
 3. In this directory run the following command `bmptk-make run`
 4. The code will flash to your arduino or the .exe will start when a native project

### cleaning a project:
 1. Open a command prompt 
 2. Use cd command to go to the directory `<path-to-your-repo>/R2D2-build/modules/<name-of-your-module>/code`
 3. In this directory run the following command `bmptk-make clean`

### IDE/Editor:
Basically every editor is allow as long as your code is compliant with the [code style guide](https://github.com/R2D2-2019/R2D2-2019/wiki/Style-Guide). Although we recommend using  "VS code" or "CLion" see the dedicated pages for both of these editors on a guide how to install those. 
> Written with [StackEdit](https://stackedit.io/).