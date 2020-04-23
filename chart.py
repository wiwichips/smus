# imports
import json
import lastfmget as APIget

# global variable that stores 24 hours represented in unix time
dayLength = 86400

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
def getScrobblesPerDay(user, numdays):

    values = []

    for i in range (0, numdays):
        values.append(APIget.getNumScrobbles(user, i + 0.5, i - 0.5))
    
    return values


# returns an array of scrobbles per month
def getScrobblesPerMonth(numMonths):
    return 3

# returns an array of scrobbles per year
#   no limit on number of years - may change this in 70 years
def getScrobblesPerYear():
    return 4

def createValuesArray(type, user):

    values = getScrobblesPerDay(user, 7)

    return values