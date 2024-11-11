n = int(input())
A = list(map(int, input().split()))
if min(A)-1 <= 0:
    print(-1)
else:
    print(min(A)-1)