n = int(input())
b = list(map(int, input().split()))
r = b[0]
for i in range(1, n):
    r += abs(b[i-1]-b[i])
print(r)
