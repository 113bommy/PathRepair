from bisect import bisect_right, bisect_left
s = [ord(i) - ord("a") for i in input()]
t = [ord(i) - ord("a") for i in input()]
index = [[] for _ in range(26)]

for i, x in enumerate(s):
    index[x].append(i)


l_s = len(s)

for x in index:
    if x:
        x.append(x[0] + l_s)

cnt = 0
for r in t:
    seq = index[r]
    if not seq:
        cnt = -2
        break
    i = cnt % l_s
    j = bisect_right(seq, i)
    cnt += seq[j] - i

print(cnt+1)



