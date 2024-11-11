a,b,c,k=map(int, input().split())
if a+b-k>=0:
    print(min(a,k))
else:
    print(a-(k-(a+b))
