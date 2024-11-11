import sys
input=sys.stdin.readline
n,m=map(int,input().split())
l=list(map(int,input().split()))
d={x:set() for x in set(l)}

for i in range(m) :
    a,b=map(int,input().split())
    if l[a-1]!=l[b-1] :
        d[l[a-1]].add(l[b-1])
        d[l[b-1]].add(l[a-1])

d=sorted(d,key=lambda x :(len(d[x])))

print(d[-1])
