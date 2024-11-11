import math

a = list(map(int, input().split()))
b = list(map(int, input().split()))
n = int(input())

s1 = math.ceil(sum(a) / 5)
s2 = math.ceil(sum(b) / 9)

print('YES' if s1+s2<=n else 'NO')