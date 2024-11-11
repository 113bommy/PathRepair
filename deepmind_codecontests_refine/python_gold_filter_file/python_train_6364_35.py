import sys

input = sys.stdin.readline

n = int(input())

a = list(map(int, input().split()))

ans = 99999999999
bestT = 0

for i in range(1, 201):
    total = 0
    for j in a:
        total += min(abs(j-(i+1)), abs(j-(i-1)), abs(j-i))
    if total < ans:
        ans = total
        bestT = i

print(str(bestT) + ' ' + str(ans))