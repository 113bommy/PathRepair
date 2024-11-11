N, H = map(int, input().split())
A = [int(a) for a in input().split()]

for i in range(N):
    B = sorted([a for a in A[:i]])[::-1]
    s = sum(B[::2])
    if s > H:
        print(i-1)
        break
else:
    print(N)
