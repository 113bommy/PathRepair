a,b,c,k = map(int,input().split())
if a+b>=k:
    print(min(k,a))
else:
    print(a-(k-a-b))