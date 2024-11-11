from sys import stdin
def input():
    return stdin.readline()
ans=[]
n,m=map(int,input().split())
d={}
r=[[] for i in range(m)]
for i in range(n):
    a,b,c=input().split()
    b,c=int(b),int(c)
    d[a]=c
    r[b-1]+=[a]
x=[]
for i in range(m):
    x=sorted(r[i],key=lambda x:-d[x])
    if len(x)==2:
        ans+=[x[0]+' '+x[1]]
    elif d[x[1]]==d[x[0]]:
        ans+=['?']
    else:
        ans+=[x[0]+' '+x[1]]
#print(d)
#print(r)
print('\n'.join(ans))
