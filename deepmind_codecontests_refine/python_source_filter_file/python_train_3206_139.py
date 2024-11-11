a,b,k = map(int,input().split())
if a-k < 0:
    b  = b + a -k
a = max(a-k,0)
print(a,b)