#imports
import requests # for get requests

### Generic functions to keep the get request process clean

## primary get request function that every get request uses

# function for lastfm get requests
def __lastfmGet(payload):
	# define headers and URL
    headers = {'user-agent': 'smus'}
    url = 'http://ws.audioscrobbler.com/2.0/'

    # Add API key and format to the payload
    payload['api_key'] = 'ad442a0e29b05a2834314212926fa974'
    payload['format'] = 'json'

    response = requests.get(url, headers=headers, params=payload)
    return response

## functions used when getting user related get requests

# adds the user from the config file to the payload
def __lastfmGetUserDefault(payload):
    # Add user to the payload
    payload['user'] = 'wiwichips' #change this to read from config

    response = __lastfmGet(payload)
    return response

# adds a non default user to the payload
def __lastfmGetUserNew(payload, user):
    # Add user to the payload
    payload['user'] = user

    response = __lastfmGet(payload)
    return response

# calls associated functions depending on user type
def __lastfmGetUser(payload, user):
    if(user == ""):
        response = __lastfmGetUserDefault(payload)
    else:
        response = __lastfmGetUserNew(payload, user)

    return response

### Function wrappers for specific get requests

# returns full json response from user.getInfo
#   pass "" if want to use the default user stored in config file
#   have to error check response after calling this function
def userGetInfo(user):
    # define payload
    payload = {
        'method': 'user.getInfo'
    }

    response = __lastfmGetUser(payload, user)
    return response

