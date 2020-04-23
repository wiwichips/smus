# imports
import argparse # for parsing command line arguments
import json
import os
import sys
import time

#import other files
import lastfmget as APIget

#create the parser
parser = argparse.ArgumentParser(description='Data visualization of '
            'music listening habbits.\nPowered by the Last.fm API.')

# Program arguments
# arguments for time frame
parser.add_argument('-w','--week', help='graphs the last week',
            action='store_true')
parser.add_argument('-m','--month', help='graphs the last 30 days', 
            action='store_true')
parser.add_argument('-y','--year', help='graphs the last 12 months',
            action='store_true')
parser.add_argument('-a','--yearly', help='graphs each year', 
            action='store_true')

#arguments for setting config options
parser.add_argument('--setuser', help='Sets the user in the config'
            'file to a passd string')

#arguments to use temporary information
parser.add_argument('--tempuser', help='Stats for a specific user')

# execute the parse_args() method
args = parser.parse_args()


# check if valid arguments were passed - print usage statement if > 1
numConflicts = 0
conflictArgs = [args.week, args.month, args.year, args.yearly]

for i in range (0,4):
    if (conflictArgs[i]):
        numConflicts = numConflicts + 1

# exit program and print usage if there are conflicting arguments
if (numConflicts > 1 or (args.setuser and args.tempuser)):
    parser.print_usage()
    sys.exit(1)


# attempt to open the shared file
from ctypes import *
library = "./libbarchart.so"
barChart = CDLL(library)

# call the driver function for testing
#barChart.driver()

# Call lastfm API


print(APIget.getNumScrobbles("", 2.5,1.5))
