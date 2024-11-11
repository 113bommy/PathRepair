n,m=map(int,input().split())
lis=[0]
for i in range(1,n+1):
    l,r=map(int,input().split())
    lis.append(l*r+lis[i-1])
v = [int(x) for x in input().split()]
s=1
for elem in v:
    if lis[s]<elem:
        s+=1
    print(s)