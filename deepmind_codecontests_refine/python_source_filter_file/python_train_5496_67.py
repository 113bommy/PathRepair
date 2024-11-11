import sys
read = sys.stdin.read

M = int(input())
dc = map(int, read().split())
dig_sum = 0
dig = 0
for d, c in zip(*[iter(dc)] * 2):
    dig_sum += d * c
    dig += c

answer = dig_sum // 9 + dig - 1
print(answer)