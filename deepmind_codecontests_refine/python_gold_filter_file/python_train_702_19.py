import collections as c

n = int(input())

a = list(map(int,input().split()))

q = int(input())

s = sum(a)

cnt = c.Counter(a)

for i in range(q):
    b,c = map(int,input().split())
    s += (c-b)*cnt[b]
    cnt[c] += cnt[b]
    cnt[b] = 0
    print(s)