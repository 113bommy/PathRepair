import re
s = input()

if len(s) > 9:
    print ("No")
else:
    p = 'A?KIHA?BA?RA?'
    r = re.compile(p)
    result = r.match(s)
    if result:
        print ("Yes")
    else:
        print ("No")
