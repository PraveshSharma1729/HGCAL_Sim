
#First source the Geant .sh file

#create folder named build
$mkdir build

# move channel position file to build
$mv channel.txt /build

# move all ring copy number to files to build
$mv copyNumber_Ring0.txt /build

# Go inside that folder
$cd build

#Do Cmake
$cmake ..

#Do make 
$make 

#run simulation
$./sim
