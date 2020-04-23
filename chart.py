# imports
import json
import lastfmget as APIget

# used to store and create the bar chart data structure
class chart:

    def __init__(self, type, user):
        self.type = type
        self.user = user
        # get the array of values (scrobbles per bar)
        self.values = createValuesArray(type, user)
    
    # method to return the values array
    def getValues(self):
        return self.values

### Functions

# returns an array of scrobbles per day
def getScrobblesPerDay(numdays):
    return 2

# returns an array of scrobbles per month
def getScrobblesPerMonth(numMonths):
    return 3

# returns an array of scrobbles per year
#   no limit on number of years - may change this in 70 years
def getScrobblesPerYear():
    return 4

def createValuesArray(type, user):

    values = ["example", "example1", "example2"]

    return values