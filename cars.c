/*
MIT License

Copyright (c) 2020 Jean-Jacques François Reibel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
Hacking C to allow writing code in C using an object oriented approach
Example: cars
*/
#include <stdio.h>

struct car{
        int wheels;
        int doors;
        int cylinders;
        int (*addWheel)(struct car*, int y);
        int (*addDoor)(struct car*, int y);
        int (*addCylinder)(struct car*, int y);
        int (*deleteWheel)(struct car*, int y);
        int (*deleteDoor)(struct car*, int y);
        int (*deleteCylinder)(struct car*, int y);
};

int addWheel(struct car* myCar, int wheelsToAdd){
        printf("Adding wheels. \n");
        myCar->wheels += wheelsToAdd;
        return myCar->wheels;
}

int addDoor(struct car* myCar, int doorsToAdd){
        printf("Adding doors. \n");
        myCar->doors += doorsToAdd;
        return myCar->doors;
}

int addCylinder(struct car* myCar, int cylindersToAdd){
        printf("Adding cylinders \n");
        myCar->cylinders += cylindersToAdd;
        return myCar->cylinders;
}

int deleteWheel(struct car* myCar, int wheelsToRipOff){
        printf("Ripping off wheels. \n");
        myCar->wheels -= wheelsToRipOff;
        return myCar->wheels;
}

int deleteDoor(struct car* myCar, int doorsToRipOff){
        printf("Ripping off doors. \n");
        myCar->doors -= doorsToRipOff;
        return myCar->doors;
}

int deleteCylinder(struct car* myCar, int cylindersToRipOff){
        printf("Ripping off cylinders \n");
        myCar->cylinders -= cylindersToRipOff;
        return myCar->cylinders;
}

int main() {
        printf("Creating car: \n");
        struct car subaru = {4, 4, 4, addWheel, addDoor, addCylinder, deleteWheel, deleteDoor, deleteCylinder};
        printf("Wheels check: %d \n", subaru.wheels);
        printf("Cylinders check: %d \n", subaru.cylinders);
        printf("Doors check: %d \n", subaru.doors);
        printf("\n");

        subaru.wheels = 5;
        printf("Added wheels directly to struct element: \n");
        printf("Wheels check: %d \n", subaru.wheels);
        printf("Cylinders check: %d \n", subaru.cylinders);
        printf("Doors check: %d \n", subaru.doors);
        printf("\n");

        subaru.deleteWheel(&subaru, 1);
        printf("Remove wheels from struct element: \n");
        printf("Wheels check: %d \n", subaru.wheels);
        printf("Cylinders check: %d \n", subaru.cylinders);
        printf("Doors check: %d \n", subaru.doors);
        
        return 0;
}