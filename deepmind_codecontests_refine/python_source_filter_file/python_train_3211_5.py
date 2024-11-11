n,z,w = map(int,input().split())
a = list(map(int,input().split()))
if (n>1):
    print(max(abs(a[-2]-a[-1]),abs(a[-1]-w)))
else:
    print(abs(a[0])-w)
