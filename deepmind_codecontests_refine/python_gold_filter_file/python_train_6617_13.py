n,n1,n2=map(int,input().split())
s=list(map(int,input().split()))
s.sort()
s.reverse()
n0=min(n1,n2)
nm=max(n1,n2)
i=0
a=0
while i<n0:
    a=a+s[i]
    i+=1
b=0
while i<n1+n2:
    b=b+s[i]
    i+=1
print(float(a/n0+b/nm))