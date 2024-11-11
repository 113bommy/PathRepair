#Johnny likes numbers
[n,k] = map(int, input().split())
x=(n//k)*k
if x>n:
    print(x)
if  x<=n:
    print(x+k)
