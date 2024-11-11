ll = lambda: list(map(int, input().split()))
s = lambda: input()
v = lambda: map(int, input().split())
ii = lambda: int(input())
m=1000000007
n=ii()
a=ll()
m=[0]*(1000001)
c=[0]*(1000001)
for i in a:
    c[i]+=1
p=0
q=[]
ans=[]
for i in range(n+1):
    if(c[i]==0):
        continue
    while(c[i]):
        if(q):
            c[i]-=1
            ans.append(q[0])
            m[q[0]]+=1
            q.pop(0)
        else:
            while(c[p] or m[p]):
                p+=1
            m[p]+=1
            ans.append(p)
            p += 1
            c[i]-=1
    q.append(i)
print(*ans)

