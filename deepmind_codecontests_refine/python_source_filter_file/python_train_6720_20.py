x=int(input())
m=0
c=0
for i in range(x):
    a,b=map(int,input().split())
    if a>b:
        m=m+1
    elif a<b:
        c=c+1
    else:
        m=m
        c=c
if m>c:
    print("Miksha")
if m<c:
    print("Chris")
if m==c:
    print("Friendship is magic!^^")