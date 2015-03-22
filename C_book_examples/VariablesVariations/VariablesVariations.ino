/*
  Variables Variations Program
  This firmware pops out messages over Serial to better understand variables' use.
  */
  
// declaring varialbles
boolean myBoolean;
char myChar;
int myInt;
float myFloat;
String myString;


void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
  myBoolean = false;
  myChar = 'A';
  myInt = 1;
  myFloat = 5.6789;
  myString = "Hello Human!!";
}

void loop() {
  // checking the boolean
  if (myBoolean) {
    Serial.println("myBoolean is true");
  } else {
    Serial.println("myBoolean is false");
  }
  
  // playing with char & int
  Serial.print("myChar is currently ");
  Serial.write(myChar);
  Serial.println();
  
  Serial.print("myInt is currently ");
  Serial.print(myInt);
  Serial.println();
  
  Serial.print("Then, here is myChar + myInt : ");
  Serial.print(myChar + myInt);
  Serial.println();
  
  // playing with float & int
  Serial.print("myFloat is : ");
  Serial.print(myFloat);
  Serial.println();
  
  // putting the content of myFloat into myInt
  myInt = myFloat;
  Serial.print("I put myFloat into myInt, and here is myInt now : ");
  Serial.println(myInt);
  
  // playing with String
  Serial.print("myString is currently: ");
  Serial.println(myString);
  
  myString += myChar; // concatenating myString with myChar
  Serial.print("myString has a length of ");
  Serial.print(myString.length()); // printing myString length
  Serial.print(" and equals now: ");
  Serial.println(myString);
  
  //myString becomes too long more than 15, removing the last 3 elements.
  if (myString.length() >= 15) {
    Serial.println("myString too long ... come on, let's clean it up!");
    myInt = myString.lastIndexOf('!'); // finding the place of the '!'
    myString = myString.substring(0, myInt+1); // removing characters
    
    Serial.print("myString is now cleaner: ");
    Serial.println(myString);
    
    // putting true into myBoolean
    myBoolean = true;
  } else {
    myBoolean = false; // resetting myBoolean to false
  }
  
  delay(5000); // let's make a pause
  
  // let's put 2 blank lines to have a clear read
  Serial.println();
  Serial.println();
  
}
