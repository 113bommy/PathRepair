import sys, os
from collections import defaultdict

if os.environ['USERNAME']=='kissz':
    inp=open('in.txt','r').readline
    def debug(*args):
        print(*args,file=sys.stderr)
else:
    inp=input
    def debug(*args):
        pass

# SCRIPT STARTS HERE
def get_hash(s):
    r=0
    for c in s:
        r*=30
        if c!='_':
            r+=ord(c)-96
    return r

def matches(s):
    R=[]
    for i in range(2**k):
        r=0
        for j in range(k):
            if i&(1<<j):
                r+=(ord(s[j])-96)*(30**(k-j-1))
        if pattern_pos[r]>=0:
            #R.append(r)
            R.append(pattern_pos[r])
    return R

n,m,k=map(int,inp().split())
    
pattern_pos=[-1]*(30**k)
#patterns=[0]*(n+1)
for i in range(n):
    p=get_hash(inp().strip())
    pattern_pos[p]=i+1
    #patterns[i+1]=p

parents=[0]*(n+1)    
edges=defaultdict(list)
failed=False
for i in range(m):
    s,l=inp().split()
    l=int(l)
    M=matches(s)
    if l in M:
        for m in M:
            if l==m: continue
            edges[l].append(m)
            parents[m]+=1
    else:
        failed=True
        break

    
if failed:
    print('NO')
else:
    Q=[]
    for i in range(1,n+1):
        if parents[i]==0:
            Q.append(i)
    
    ans=[]
    while Q:
        i=Q.pop()
        ans.append(i)
        for child in edges[i]:
            parents[child]-=1
            if parents[child]==0:
                Q.append(child)
    if len(ans)==n:
        print('YES')
        print(ans)
    else:
        print('NO')
    