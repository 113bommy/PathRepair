n = int(input())
r = int((2*n)**.5)
if 2*n!=r*(r+1):
    print('No')
    exit()

# 三角数
res = [[]]
cnt = 1
num = 1
for i in range(r):
    l = list(range(cnt,cnt+num))
    res.append(l)
    for j,k in enumerate(l):
        res[j] += [k]
    cnt += num
    num += 1

print('Yes')
print(len(res))
for l in res:
    print(len(l),*l)
