
#First source the Geant .sh file

#create folder named build
$mkdir build

# move channel position file to build
$mv channel.txt /build

# Go inside that folder
$cd build

#Do Cmake
$cmake ..

#Do make 
$make 

#run simulation
$./sim
