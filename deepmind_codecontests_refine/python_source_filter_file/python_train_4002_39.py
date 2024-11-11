import re
st = input().rstrip()
y = re.search(r'^(?=.+[0-9])(?=.+[a-z])(?=.+[A-Z]).{5,}$',st)
if(y == None):
    print('Too weak')
else:
    print("Correct")





