n,k = map(int,input().split())
for _ in range (k):
    if n%10:
        n=n-1
    else:
        n=n//10
    print(n)
print(n)