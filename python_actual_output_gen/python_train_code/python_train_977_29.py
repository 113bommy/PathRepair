n,m,d = map(int,input().split())
if d == 0:
    c = n
else:
    c = (n-1)*2
print(c*(m-1)/n**2)