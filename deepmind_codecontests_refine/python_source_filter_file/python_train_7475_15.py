n,q=map(int,input().split())
s=input()
c=[0]
t=0
for i in range(1,n+1):
    t+=1 if (s[i-1]=='A' and s[i]=='C') else 0
    c.append(t)
for i in range(q):
    l,r=map(int,input().split())
    print(c[r-1]-c[l-1])
