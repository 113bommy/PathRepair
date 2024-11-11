import sys

input = sys.stdin.readline

n = int(input())

m = n // 2 + 1

print(m)

for i in range((n + 1)//2):
    print(1, i + 1)


for i in range(n//2):
    print(m, m - n // 2 + i + 1)
