import collections as c

n = int(input())

a = list(map(int,input().split()))

q = int(input())

s = sum(a)

cnt = c.Counter(a)

for i in range(q):
    b,c = map(int,input().split())
    s += (c-b)*cnt[b-1]
    cnt[c-1] += cnt[b-1]
    cnt[b-1] = 0
    print(s)