x,y,z = list(map(int,input().split()))
tot = 0
for i in range(1,z+1):
    tot+=(x*i)
if y-tot <=0:
    print(0)
else:
    print(tot-y)
    