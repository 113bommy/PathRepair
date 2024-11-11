a,b,c,k = map(int,input().split())
if a+b>=k:
    print(max(a, k))
else:
    print(a-(k-a-b))