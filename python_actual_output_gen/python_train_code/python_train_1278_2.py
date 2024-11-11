from sys import stdin
input = stdin.buffer.readline
n = int(input())

lst = list(map(int, input().split()))

if n <= 1:
    print(1)
    exit()


for i in range(1, n):
    lst[i] += lst[i-1]

from collections import Counter
cnter = Counter(lst)
t = cnter.most_common(1)
# print(t)
print(n- t[0][1])
