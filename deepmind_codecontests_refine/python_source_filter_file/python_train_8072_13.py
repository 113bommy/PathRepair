n=int(input())
l=list(map(int, input().split()))
a=sum(l)
b=a/2
c=0
i=0
while b>c:
    c=c+l[i]
    i=i+1
c=c-l[i-1]
j=len(l)-1
d=0
s=0
while b>d:
    d=d+l[j]
    j=j-1
    s=s+1
d=d-l[j+1]
if c==d:
    print(i, s-1)
if c>d:
    print(i-1, s)
if c<d:
    print(i, s-1)
