At first you need to open proteus file. Here we have developed our circuit. With MQ4 we will measure  ammount of methane in ppm. 
We need to use MQ135 to measure the ammount of CO2, but this MQ135 or K30 which are used in measuring CO2 is not available for proteus. 
So in proteus we have built circuit for MQ7 which is used in measuring CO. The circuit is same, 
just in real world we need to replace MQ7 with MQ-135.


We have deveoped code for this circuit in arduino assuming MQ135 used. We have also added GPS & SD card to get location & to store information.
We need many library functions which are attached with this folder.

Proteus library function need to put on the instruent to run the siulation & to run code in arduino library function need to add in libray 