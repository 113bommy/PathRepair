N,K = map(int,input().split())
x = 0
while N > K:
    n = N//K
    x += 1
print(x)