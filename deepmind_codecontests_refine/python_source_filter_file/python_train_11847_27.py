n, a, b = list(map(int, input().split()))
k = b - a
if k % 2 == 1:
    print(min(a-1, n-b)+1+(z-1)//2)
else:
    print(z//2)
