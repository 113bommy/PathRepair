a,b = map(int,input().split())
f = d = s = 0
for i in range(1,7,1):
    if abs(i-a) < abs(i-b):
        s +=1
    elif abs(i-a) > abs(i-b):
        f +=1
    else:
        d +=1
print(f , d, s)