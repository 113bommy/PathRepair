def check(s):
    x=s[0:len(s):2]
    y=s[1:len(s):2]
    X="W"*4
    Y="B"*4
    if (x==X and y==Y) or (x==Y and y==X):
        return True
    return False
    
f=0
for _ in range(8):
    s=input()
    if check(s):
        continue
    else:
        f=1 
        break
if f:
    print("NO")
else:
    print("Y")