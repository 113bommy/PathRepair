n, k, c = map(int, input().split())
s = input() + "?"

l, r = [], []
cur = 0
count = 0

while cur <= n:
    if s[cur] == "o":
        count += 1
        l.append((count, cur+1))
        cur += c

    cur += 1

cur = n
count = k

while cur >= 0:
    if s[cur] == "o":
        r.append((count, cur+1))
        count -= 1
        cur -= c

    cur -= 1

ans = (i[1] for i in set(l) & set(r))
for i in sorted(ans):
    print(i)