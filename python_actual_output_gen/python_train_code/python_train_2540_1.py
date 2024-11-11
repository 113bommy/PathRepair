# import sys

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

n = int(input())
lst = list(map(int, input().split(' ')))

ans = 1
cur = min(len(lst), lst[-1])
for i in range(1, n):
    if cur <= 0:
        ans += 1
    if cur < lst[len(lst) - i - 1]:
        cur = lst[len(lst) - i - 1]
    else:
        cur -= 1

print(ans)
