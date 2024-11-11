n, m = map(int, input().split())
x = list(map(int, input().split()))
d = dict.fromkeys(x, False)
tmp = list(map(int, input().split()))
for i in range(m):
    if tmp[i] in d:
        d[tmp[i]] = True
for k, v in d.items():
    if v == True:
        print(k,end=' ')