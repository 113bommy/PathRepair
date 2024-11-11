n,a,b = map(int,input().split())
s = 0
if n==a+b:
    print(1)
else:
    for i in range(1,n-1):
        s = max(s,min(a//i,b//(n-i)))
    
print(s)