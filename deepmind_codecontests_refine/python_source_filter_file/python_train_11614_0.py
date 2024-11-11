import sys
n,a,b=map(int,input().split())

h=list(map(int,input().split()))

t=h[-1]
h[-1]-=t*b
h[-2]-=t*a
h[-3]-=t*b

res=[sys.maxsize,None]

cnt=[0]*n

def search(idx,cur):
    if idx==n-1:
        res[0]=cur
        cnt[n-2]+=t
        res[1]=cnt[:]
        return
    x=(h[idx-1]// b+1) if h[idx-1]>=0 else 0
    while cur+x<res[0]:
        h[idx-1]-=x*b
        h[idx]-=x*a
        h[idx+1]-=x*b
        cnt[idx]=x
        search(idx+1,cur+x)
        h[idx-1]+=x*b
        h[idx]+=x*a
        h[idx+1]+=x*b
        x+=1

search(1,t)

print(res[0])

s=[]
for i in range(n):
    for j in range(res[1][i]):
        s.append(str(i+1))
        
print(' '.join(s))