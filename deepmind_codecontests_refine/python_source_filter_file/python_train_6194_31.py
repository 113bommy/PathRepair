N = int(input())
A = list(map(int, input().split()))
mina = min(A)
if mina == 1:
    print(-1)
else:
    print(mina - 1)
