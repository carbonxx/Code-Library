# A program which uses request library

import requests # pip install requests
  
  
url = str(input("Enter the api url: ")) # like https://catfact.ninja/fact
response = requests.get(url)

if response.status_code == 200:
  data = response.json()
  if "catfact.ninja/fact" in url:
    print(data["fact"])
  else:
    print(data)
else:
  print(f"Error Code: {response.status_code}")
  
response.close()
