#imports
import argparse # for parsing command line arguments
import json
import os
import sys

#import other files
import lastfmget as APIget

## functions
#delete this function later - just used for testing
def jprint(obj):
    # create a formatted string of the Python JSON object
    text = json.dumps(obj, sort_keys=True, indent=4)
    print(text)

#create the parser
my_parser = argparse.ArgumentParser(description='Data visualization of music listening habbits.\nPowered by the Last.fm API.',
			epilog='The CLI Scrobbler Statistic Analysis program',
			prefix_chars='-')

#execute the parse_args() method
args = my_parser.parse_args()

# attempt to open the shared file
from ctypes import *
library = "./libbarchart.so"
barChart = CDLL(library)

# call the driver function for testing
#barChart.driver()

# Call lastfm API
payload = {
    'method': 'user.getInfo'
}
r = APIget.__lastfmGetUserDefault(payload)
jprint(r.json()['user']['playcount'])

