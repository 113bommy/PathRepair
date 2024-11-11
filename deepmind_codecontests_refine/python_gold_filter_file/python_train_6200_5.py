import collections

n = int(input())
s = list(map(int, input().split()))
c = collections.Counter()
for i in s:
    c[i] += 1

pow = [2**x for x in range(1,32)]

ans = 0
for i in s:
    for j in pow:
        if i >= j:
            continue
        elif i == j//2:
            ans += c[i]-1
        elif j-i in c:
            ans += c[j-i]

print(ans//2)