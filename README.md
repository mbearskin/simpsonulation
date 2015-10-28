# simpsonulation
Intro to C++ final assigment 
This is assigment 9 and 10 

Prompt for 9:
Background: You've done well to help Marge in so many ways.  Now, you are going to do something new and much more fun.  You're going to write a program that will help Marge understand just how she fits into her world.  You're going to write a program that is a simulation of life in the Simpsons' household from the Marge point of view.  This program will work in conjunction with hw 10.  The classes you create in this assignment will be expanded/extended/modified/added to in hw 10.  Assignment 9 is the "testing ground" for basic classes for the simulation, and assignment 10 will be a real (unreal) hoot!

Here's a brief summary of what assignments 9 and 10 will entail.  You will create a house class whose primary data member is a 2-D array that represents the floor plan of the house object.  You will have different "actors" that will interact with each other in a simulation of life in the Simpson's household.  A "cleaner" object (named Marge) will move about with her vacuum trying to keep up with all the mess her family makes.  There will be trash strewed about, family members adding trash, etc.

So, in this part of the project, you will create classes and then test them.  You'll have to define the classes and their functionality, then declare objects of those types, then have them call their member functions to see that they work.

Specifications:  You are to create the following classes.  Remember to put the definition of each class in its own header, and the definitions of member functions in their own .cpp files.  One class per file, two files per class.

class cleaner:
    data members:
name
stress level (an integer between and including 0 and 100)
location (on the floor, in the house)
    member functions:

a constructor that has two parameters:  a string or ntca that will be the object's name; some construct(s)1 that will establish the object's location in a 2-D array, defaulted to (0,0).  This constructor will set the object's name and location using the args passed.  It will also give the object an initial stress level of 0.  
a calc_stress() function that returns nothing, but has one parameter of type house. This function will "scan" the house argument passed and set the stress_level member accordingly.  The stress_level will be set to the rounded down proportion of the house's floor plan that is covered with trash.  Thus, if the house is a 2-D array 25 x 25, and there are 42 pieces of trash, then stress_level is (42/(25*25)) * 100% rounded = 18 6.  But, wait, there's more!  Every instance of a person the cleaner finds in the scan will add two points to this calculation. So, in this same example, if there were two people in the house, then the stress_level would be 10.  This calculation is not to exceed 100, of course.
an overloaded insertion operator that will output the object in this format:  < name> is at <location> stressed at level <stress_level>. You can make this a 'print()' function until we show you how to overload the insertion operator for classes.
appropriately needed accessor and mutator functions.
class family_member:

    data members:

a name (ntca or string).
a location
an (integer) sloppiness_factor on a scale of 0->100.
    member functions:

a constructor that initializes the location to a default location (0,0).  Furthermore, it will access an input file named "family_member.txt" in order determine the objects name and sloppiness_factor, this done by randomly choosing one such pair (see file below).
an overloaded insertion operator that will output the object in the format:  < name > is at < location > has sloppiness < sloppiness_factor >  You can make this a 'print()' function until we show you how to overload the insertion operator for classes.
appropriately needed accessor and mutator functions.


class house:
    data members:

a 2-D array of characters with maximum size of 25 x 25.  (Make a constant in this class's header file to be used for creating this array.) We'll refer to this as the "floor".
an unsigned short to represent the size of a particular house object.  Call this member "size"; it should never be bigger than 25, the max size of a house.
an unsigned short to represent the initial number of trash items on the floor (in the house).
    member functions:

a constructor that has parameters for the size of the house, and the number of trash items. This constructor will also be passed a cleaner object, and a family_member object, both of which it will place at random locations on the floor by placing a letter in that location.  The letter used for each will be the first letter of the object's name member variable.  For example, if the cleaner's name is "Marge", then place a 'M' where Marge is located. The constructor then calls the scatter_trash function.  When each thing is placed on the floor, it should not be place on top of another person or piece of trash....or anything else.  Once the people are placed, their location  member needs to updated to reflect their new location value.
an overloaded insertion operator that will output the house (floor grid) to show where the cleaner, trash, and family_member(s) are.  You can make this a 'print()' function until we show you how to overload the insertion operator for classes.
a private function called scatter_trash that will place the initial trash items at random locations in the house.  The constructor should call this function.  The function should place a 't' in random locations on the floor.
Now that you have your classes, write a main function that will create a cleaner named "Marge", then a family_member, and a house that you pass cleaner and family_member to.  Output the house, then the cleaner, and then the family_member.  Have Marge call her calc_stress() function and output Marge again.

Note:  you should have at least 8 files for this programming project.

Family_members file: This is the data that should be in your family_members file:  (name followed by sloppiness_factor)

    Homer    98

    Bart       73

    Lisa        2

    maggie    37

    

When you submit:  do it.

1It will be up to you how you want to represent the location of an object in the house (a 2-D array).  You can either make a struct point, or keep two values for coordinates......you choose.

Prompt for 10:
Background, Presentground, Foreground:  As you already know, this assignment is tied in with assignment 09.  The constructions you put together for that assignment are the foundation for this one.  You are going to modify those classes, add other classes to those, and create a main function that will simulate interaction between these "players".  Your players will be the cleaner (assumed to be named Marge), the family members (assumed to be named Homer, Bart, Lisa, and Maggie), pieces of trash, and a trashcan. The simulation will generally work like this:  you declare a cleaner and an array of 4 family members. These are passed to the constructor of a house you declare.  The house randomly places some number of trash items (representing the initial state of the messy house), then places the cleaner and the family members and the trashcan at random locations (all of which occupy unoccupied locations - don't allow Bart to be placed on top of trash, Homer to be placed in the trashcan where he belongs, Maggie to be placed on top of Marge, etc).  Then, to simulate a day's labor cleaning and trashing, in each time unit each of Marge and the family members will move in turn (beginning with the cleaner Marge).  Marge will activate her vacuum's vac function to clean up her new location, family members will drop trash (or not).  If Marge encounters the trashcan, she empties the vacuum and then continues.  The simulation ends when one of the following occurs:
Marge is electrocuted by the vacuum which sucked up something that causes a short.
Marge is killed by an exploding vacuum which has exceeded its capacity.
Marge has nothing else to vacuum.
Marge has a (deadly) aneurism due to skyrocketed stress level caused by too much trash.
Marge falls out a window while cleaning. (If this happens, the fall kills her.)

Specifications: You will need code the following classes:

First, modify the house class to have its constructor accept an array of family_member instead of just one.  Thus, the constructor will set the size of the floor (remember, max 25!), call its private clear() function, call its private scatter_trash() function, randomly place the cleaner and update its location variable, randomly place the family members and update their locations, randomly place the trash can (use 'C').  In addition, you will have the outer cells of the 2-D array representing the floor (house) be walls and windows.  Use 'b' for wall, and use 'W' for windows.  Place a window every fourth non-corner cell in all four walls, beginning from whichever corner you like.  Now, you're going to find that you will have trouble representing with one char what is happening in each cell of the floor.  I'd suggest you read over this entire problem statement before you decided exactly what  you will have a 2-D array of.  An array of chars probably won't cut it.  Think about an array of cells (of some struct type) that will "keep" all the info you need.
Second, modify the cleaner class to have another member variable of type vacuum.  This type object is described next.  The cleaner  will also have to have a member to describe her as alive or not.  Also, the cleaner will have to have a step() function that determines which is the next cell (adjacent, since cleaner Marge's hair prevents successful flight) she goes to, and then what action she takes next. If the trashcan is there, she empties the vacuum. (You can either have her stand on the trashcan, or remain where she was to empty the bag.) If a piece of trash is there, she activates her vacuum's vac() function and passes the trash to it. If a family member is there, she finds another place to step.  And at each step, Marge has to determine if she is done cleaning or if she is due for an aneurism (stress of 100 kills her) , she has been electrocuted, fallen out of a window, or exploded. So where does the trash item come from? Your code will have to create it (declare it) "on the fly".  That doesn't mean you create trash with flies on it, it means you have code that declares that item right there in that scope.  Then feed it to the vacuum cleaner.  You can write your code for the cleaner's step() function however you want. You can make the next location randomly chosen, or chosen some "smart" way.  It's up to you.  But randomness is really funny!  (Remember, next location is up, down, left, or right only.)
Third, modify family_member to have a drop_trash() function that will use their sloppiness_factor  to determine whether or not they leave a trash item (place a 't') in their location.  They also have a step() function that randomly picks a new location to go (same as cleaner - one cell per step).
Fourth, create a vacuum class:
                             class vacuum:

                                    data members:        

an array of trash items called bag sized at 35 (a constant of course, established in the vac class).
an int to represent the number of trash items in the trash bag.
a member to record its status as shorted out.
                                    member functions: 

a default constructor that sets the contents to 0 and that it is not shorted out (a good thing).
a vac() function that activates the vacuuming action of the device.  It will return nothing, but is passed a trash item that it copies into its bag member (array) variable and increments its contents.  If you would like to write this function as an overloaded member insertion operator because it seems funny, go ahead.  (inserting trash into the vacuum?  get it, get it??)  This function will also need to determine whether or not the vacuum explodes or shorts out, and what the consequences are and how to implement that is up to you.
a empty() function that empties the contents of the bag in to the trashcan.  Note: there is no trashcan-type object.  When Marge encounters a trashcan ( 'C' ) on the floor, she has her vacuum call its empty() function which displays the contents to the screen while dumping it into a blackhole, i.e. it just goes away, also causing global warming.
you might want to included an isExploded() and an isSparky() function that the cleaner can use to determine her/his fate.                                        
    4. Fifth, create a trash class:
                            class trash
                                            data members:
a string for the name of the item.
an int for the potential to cause a short (0 -> 100)                                         
                                    member functions: 
a constructor that sets the name of the item and its potential.  Potential and name are read from a file.  
appropriate accessor(s).              
In addition, if any player (cleaner or family_member) steps into a window cell, that means they just fell out the window.  Who cares if it was a family member; all they ever did was spread trash.  They're dead and no longer move about; no zombies in the Simpsons family.  If the cleaner falls out, she is dead and the simulation ends.  At each time step in this simulation, your code should output the house so that you can see how everyone has moved.  When you submit, comment out that line of code so as not to generate a zillion pages of output.

Now, in all the above classes, you may have to add other functions or members to make this all work. Do so, but do it with thought! You might need to add mutators/accessors, but do it only if you need them and code them safely.  If you wish to make interesting additional functionality, be sure to write a good comment at the beginning of your main to let the grader know.  For example, you might want to allow Marge to vacuum family members.  In doing so, you have to decide what happens.  Maybe you would like to read from a file what that person "says" when vacuumed, e.g. Homer says "blbllblblblblblbl" to emulate his blubber being caught in the vacuum, Bart might say "don't have a cow, man", etc.  Think about who might actually get sucked up into the vacuum.  There are many possibilities!

The Driver:  You will have your main function declare the objects (in the right order, mind you) and run the simulation of the players' lives in their little house of horrors.  So, what is simulation?  Clearly, you will have a loop, each iteration of which has everyone taking a step and doing their thing.  It stops under the conditions outlined above.  Output the final status of the house:  who died, and how the cleaner died if he/she expired. Don't comment out the very last floor output.

As we get closer to the submit date, we may change the simulation parameters, such as initial number of trash items to scatter, house size, etc.

Interesting note:  Marge's stress level actually goes down when a family member falls out a window and dies!

The trash file: Here's what you will want to start your trash.dat file with:

    59 beer can
    34 saxophone
    4 Maggie poop
    19 hairball
    23 stink bomb
    15 Krustyburger
    19 floor-pie
    8 pacifier
    12 Millhouse
    16 Snowball
    35 skateboard
    67 Lisa's braces
    76 bar of radioactive uranium isotope
    0 Flanders
    4 Ralph Wiggum
    10 Quimby's sash
    23 Grandpa's dentures
    3 Nate Eloe
    5 cigarette butts
    9 kleenex
    10 toilet brush
    8 toilet plunger
    6 tv remote
    12 can of spam
    90 wad of steel wool
    24 cattle prod
    34 electric fencer
    13 sling shot
    2 a shoe
    9 a foot
    10 whoopee cushion
    50 anti-matter
    7 unsigned int
    33 keys
    2 mustard packet
    5 gremlin   
    6 krusty doll
    8 roomba

....and you can add whatever you want.
