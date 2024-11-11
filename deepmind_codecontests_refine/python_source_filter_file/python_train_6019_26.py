n=int(input());d=[0]*20001;a=1;b=-1
for i in range(n):
    c=int(input())
    if b!=c:
        a+=d[c]
        d[c]=a
    b=c
print(a%(10**9+7))