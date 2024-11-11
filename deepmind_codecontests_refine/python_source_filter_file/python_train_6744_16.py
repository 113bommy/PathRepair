N = int(input())
A = list(map(int, input().split()))
c = [] * N
for i in A:
    c[i-1] += 1
print(*c)