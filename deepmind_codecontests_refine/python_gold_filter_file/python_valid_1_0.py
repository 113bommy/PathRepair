n = int(input())
num = [0, 0, 0, 0]

for _ in range(n):
    x, y = map(int, input().split())
    num[bool(x&2) + (y&2)] += 1

print((n*(n-1)*(n-2))//6 - num[0]*num[1]*num[2] - num[0]*num[1]*num[3] - num[0]*num[2]*num[3] - num[1]*num[2]*num[3])
