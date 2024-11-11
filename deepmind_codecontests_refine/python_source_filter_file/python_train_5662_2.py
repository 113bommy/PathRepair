x = str(input())
y = str(input())

s = True

n = len(x)
m = len(y)

if n == m:
    if n == 1:
        s = x == y
    elif "1" in x:
        s = True
    else:
        s = x == y
else:
    s = False
    
if s:
    print("YES")
else:
    print("NO")