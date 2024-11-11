n,*a=map(int,open(0).read().split())
s=1
if 0 in a:
    print(0)
    exit()
for i in a:
    s*=a
    if  s > 10**18:
        print(-1)
        exit()
print(s)