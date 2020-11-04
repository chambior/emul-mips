typedef char* string;

/*Function 'string_equal'
Check if two strings are the same
Considers any 0x00 char as the end of the string
Args:
    'a' : Input string 1, char*
    'b' : Input string 2, char*
Outputs:
    1 if a and b are the same, 0 if not
*/
short string_equal(string a, string b);

/*Function 'remove_period'
Replaces the first period char of the string with a '0x00' char
Considers any 0x00 char as the end of the string
Do nothing if 0x00 char is reached before a period
Args:
    's' : Input and output string, char*
Outputs:
    Nothing
*/
void remove_period(string s);

/*
Converts a given string into a char equivalent to the represented register
Supports:
    $1 to $32 written as precedes
    MORE WIP
Args:
    's' : Input string, represents a register
Outputs:
    char : equals to the represented register number
*/
char get_reg(string s);

/*
Converts a given string into a int equivalent to the represented number

*/
int get_immediate(string s);





char get_instruction_type(string s);
