n=int(input())
a=list(map(int,input().split()))
b=sorted(a)
c=[0]
d=[0]
s1,s2=0,0
for i in range(n):
    s1=s1+a[i]
    s2=s2+a[i]
    c.append(s1)
    d.append(s2)
    
for _ in range(int(input())):
    type,l,r=map(int,input().split())
    s=0
    if type==1:
        print(c[r]-c[l-1])
    else:
        print(d[r]-d[l-1])