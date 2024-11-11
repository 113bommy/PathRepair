S = list(input())
res = len(S)
kind_all = set(S)
for i in kind_all:
    temp = S.split(i)
    cnt = 0
    for j in temp:
        cnt = max(cnt,len(j))
    res = min(res,cnt)
print(res)