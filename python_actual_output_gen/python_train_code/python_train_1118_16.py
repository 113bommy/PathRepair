a,b,k = map(int,input().split())
if k > a:
    print(0,a+b-k)
else:
    print(a-k,b)