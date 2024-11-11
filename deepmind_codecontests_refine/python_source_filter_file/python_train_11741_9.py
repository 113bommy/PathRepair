n=int(input())
a=list(map(int,input().split()))
if n==0:
    print(0 if a[0]==1 else -1)
    exit()
e=[1-a[0]]
for i in range(n):
    e.append(max(e[i]-a[i],0)*2)
#print(e)
p=[i for i in a]
for i in range(n-1,-1,-1):
    if -p[i+1]//2*-1+p[i]>e[i]:
        print(-1)
        exit()
    if p[i+1]+p[i]>e[i]:
        p[i]=e[i]
    else:
        p[i]+=p[i+1]
print(sum(p))
#print(p)