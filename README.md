# NextClass
A program which can be used to check information about only the next event you need to go to

classsheet.txt is the file containing the schedule

The number and time (eg. 2 16:40) are the day of the week and time in 24-hour format, with zero being sunday. 
This time is the END of the event, after which the program will output the following event

There is a newline after the end time, which signifies the start of the output message. 
This can be anything you want, as long as it does not contain "\n\n" since that is how the program parses the next event

DO NOT remove the padding for edge case at 8 00:00
