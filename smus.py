#imports
import argparse # for parsing command line arguments
import requests # for get requests
import json
import os
import sys

## functions
# function for lastfm get requests
def lastfm_get(method):
	# define headers and URL
    headers = {'user-agent': 'smus'}
    url = 'http://ws.audioscrobbler.com/2.0/'

    # Add API key and format to the payload
    payload = {
		'api_key': 'ad442a0e29b05a2834314212926fa974',
		'user': 'wiwichips',
		'method': method,
		'format': 'json'
	}

    response = requests.get(url, headers=headers, params=payload)
    return response

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
r = lastfm_get('user.getInfo');
jprint(r.json()['user']['playcount'])

