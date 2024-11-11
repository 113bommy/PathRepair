from bisect import bisect_left
s = input()
t = input()
alpha = [[] for _ in range(26)]
def f(c): return ord(c)-ord("a")

for i,c in enumerate(s): alpha[f(c)].append(i)
idx = -1
roop = 0
for c in t:
    lst = alpha[f(c)]
    if not lst:
        ans = -1
        break
    i = bisect_left(lst,idx)
    if i == len(lst):
        roop += 1
        idx = lst[0]
    else:
        idx = lst[i]
else:
    ans = len(s)*roop+idx+1
print(ans)