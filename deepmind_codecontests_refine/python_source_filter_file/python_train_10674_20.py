n = int(input())
m = n%7
t = n//7*2
if m<=5:
    a = t
else:
    a = t-5
if m<=2:
    b = t+m
else:
    b = t+2
print(a,b)