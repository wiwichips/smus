#imports
import requests # for get requests

## Generic functions to keep the get request process clean
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

## Function wrappers