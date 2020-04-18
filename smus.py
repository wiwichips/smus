#import the argparse library
import argparse

import os
import sys

#create the parser
my_parser = argparse.ArgumentParser(description='Data visualization of music listening habbits.\nPowered by the Last.fm API.',
			epilog='The CLI Scrobbler Statistic Analysis program',
			prefix_chars='-')

#execute the parse_args() method
args = my_parser.parse_args()

