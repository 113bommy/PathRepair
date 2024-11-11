n,q=list(map(int,input().split()))
s=input()
d=dict()
for i in range(n):
    d[i]=(ord(s[i])-96)
l=[]
s=0
for i in range(n):
    s+=d[i]
    l.append(s)
for _ in range(q):
    a,b=map(int,input().split())
    if a==1:
        print(l[b-1])
    else:
        print(l[b-1]-l[a-1])