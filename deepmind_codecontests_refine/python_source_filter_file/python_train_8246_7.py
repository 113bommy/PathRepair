import re
n=int(input());s=input();y='z'
while'a'<y:
    x=y+'*'
    y=chr(ord(y)-1)
    # print(x+y+x)
    s=re.sub(x+y+x,y,s)
    print(s)

print(n-len(s))