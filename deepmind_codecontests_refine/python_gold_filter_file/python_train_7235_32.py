n = int(input())
b = list(map(int, input().split()))
r = abs(b[0])
for i in range(1, n):
    r += abs(b[i]-b[i-1])
print(r)
