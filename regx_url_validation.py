
#using regx to validate url
import re
 
pattern = "^https:\/\/[0-9A-z.]+.[0-9A-z.]+.[a-z]+$"
result = re.match(pattern, "https://www.google.com")

if result: 
    print(result)
else:
    print("Invalid URL")
