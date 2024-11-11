import collections

N = int(input())

S = collections.Counter(list(input()))
for i in range(N-1):
    c = collections.Counter(list(input()))
    S &= c

ans = []
for i in S.items():
    ans += i[0]*i[1]
A.sort()
print(*ans, sep="")