n = int(input())
a = list(map(int,input().split()))

c = 0
for i in range(2,n):
    c = c^a[i]

start = a[0]
a,b = a[0],a[1]
if((a^b)==c):
    print(0)
    exit()

dif = a+b-c
if(dif%2==1):
    print(-1)
    exit()

dif = dif//2
for i in range(40):
    if((c >> i)&1)&((dif >> i)&1):
        print(-1)
        exit()

if(dif > c):
    print(-1)
    exit()

goal = dif

for i in range(40,-1,-1):
    if(c >> i)&1:
        if(goal + 2**i <= start):
            goal += 2**i

if(goal==0):
    print(-1)
    exit()

print(start-goal)
