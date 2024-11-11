n=int(input())
p = list(map(int,input().strip().split()))
sor = sorted(p)
t=0
for i in range(0,(n-1)):
    dif=sor[n-1]-sor[i]
    t=t+dif
print(t)



