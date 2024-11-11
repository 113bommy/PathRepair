N,M = map(int, input().split())
if N==M==1:
    print(1)
elif n == 1 or m == 1:
    print(max(N,M)-2)
else:
    print((N-2) * (M-2))