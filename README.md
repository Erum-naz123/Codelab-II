Challenge 1 — CO₂ Calculator 

Approach and logic: 
The completed C++ program estimates emissions from a car journey using distance in miles 
and a petrol or diesel selection. It applies the assessment constants: 9.66 litres per 100 miles, 
2.31 kg CO₂ per litre for petrol and 2.68 kg for diesel (Bath Spa University, 2026a). The 
calculation multiplies miles by 9.66/100 to obtain litres used, then multiplies by the relevant 
emission factor. This gives a comparable estimate rather than a measurement of a particular 
car's emissions. 
Functions and decisions: 
I 
organised the solution into getDistance(), getFuelType() and calculateEmissions(). 
getDistance() uses a loop to reject negative and non-numeric values. getFuelType() accepts 
either uppercase or lowercase P and D, repeating its prompt for other entries. 
calculateEmissions() stores the constants locally and uses a conditional expression to select 
the correct factor. The main() function coordinates these calls and uses fixed with 
setprecision(2) to display the answer in kilograms. Separating the steps makes the arithmetic 
and input checks easier to follow. 

Verification and reflection: 
I 
compiled the supplied source with the C++17 compiler and tested a 100-mile petrol 
example, which produced 22.31 kg CO₂. The code has 51 lines, within the 100-line limit. 
Further checks the student should perform include zero distance, diesel and invalid entries. 
A limitation is that real journeys can have different consumption rates due to driving 
conditions and vehicle efficiency. 

Challenge 2 — Alexa Tell Me a Joke 

Approach and logic: 
The joke program reads the supplied randomJokes.txt file and responds to the exact 
command 'Alexa, tell me a joke' (Bath Spa University, 2026a). Each usable line contains a 
setup and punchline separated by a question mark. loadJokes() opens the file with ifstream, 
reads it using getline() and stores lines containing a question mark in a vector<string>. If the 
file cannot be opened, an error message is printed; if the resulting vector is empty, the 
program exits. The jokes can therefore be edited without changing the C++ source. 

Functions and decisions: 
In main(), a while loop repeatedly requests a command using getline(), which preserves 
spaces and punctuation. Only the specified phrase triggers a joke; 'quit' and 'Quit' end the 
session. A Mersenne Twister generator (mt19937) and uniform_int_distribution choose a 
random index from the loaded vector. tellJoke() finds the first question mark, prints the 
setup, waits for Enter and then prints the remaining text after trimming leading whitespace. 
This means the punchline is not shown before the reader is ready. 

Verification and reflection: 
I compiled the file under C++17 and checked a request followed by Enter and 'quit'; the setup 
appeared before the punchline. The source contains 58 lines, below its 100-line maximum. 
The user should additionally confirm the missing-file message and repeated random 
selections. The exact-match command is straightforward but intentionally does not 
recognise alternative wording. 

Challenge 3 — Book Manager 

Approach and logic: 
The Book Manager is a menu-driven C++ program using the supplied bookData.txt dataset. 
Each record contains a title, author, page count, three-digit ID and borrowed status, 
matching the task sheet (Bath Spa University, 2026a). A Book class holds those five attributes 
and has a display() method for consistent console output. loadBooks() reads each row 
through ifstream and stringstream, separates its comma-delimited fields and converts the 
page count with stoi(). Invalid fields and malformed rows are reported and skipped; valid 
records are collected in a vector<Book>. 

Functions and decisions: 
The main menu supports viewing every book, viewing a specific ID, borrowing, returning and 
quitting. findBook() searches the vector by string ID, preserving leading zeroes such as 001. 
The two extra options prevent borrowing an already borrowed book or returning an 
available book. When status changes, saveBooks() rewrites the dataset using ofstream so 
the new status persists after the program closes. If saving fails, the in-memory change is 
reversed.  
Keeping loading, searching, displaying and saving separate simplifies the control flow. 

Verification and reflection: 
The program compiled under C++17, and a menu test displayed the book records and looked 
up ID 001. It has 124 lines, below the 200-line maximum. The user should also check 
borrow/return persistence and invalid menu choices before submission. The dataset is a 
simple comma-separated format; titles containing commas would require a more 
sophisticated parser. 
AI acknowledgement 
I acknowledge the I haven’t used any AI for this assignment help or guidance. 

References (Harvard style) 
Bath Spa University (2026a) Coding Tasks Assessment 1. Unpublished assessment task sheet 
supplied through Ultra. 
Bath Spa University (2026b) Programming Skills Portfolio: Assessment 1. Unpublished 
module assessment brief.
