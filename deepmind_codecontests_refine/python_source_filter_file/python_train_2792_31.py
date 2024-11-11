n,m,d = map(int,input().split())
c = 0
if d!=0:
    c = (n-2*d)*2+n
else:
    c = n
print(c/n/n*(m-1))