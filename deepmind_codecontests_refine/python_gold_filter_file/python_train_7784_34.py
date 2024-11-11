n,m = map(int, input().split())
if n % 2 != 0:
    for i in range(1,m+1):
        print(i,n+1-i)
else:
    x = n//2
    for i in range((m+1)//2):
        print(i+1,x-i)
    for i in range(m//2):
        print(x+1+i, n-1-i)