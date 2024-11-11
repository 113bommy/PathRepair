a,b=[int(x) for x in input().split()]
f=0
s=0
t=0
for i in range(1,7):
    if abs(i-a) > abs(i-b):
        f=f+1
    elif abs(i-a) < abs(i-b):
        s=s+1
    else:
        t=t+1
print(f) 
print(t)
print(s)