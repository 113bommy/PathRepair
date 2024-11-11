l = {}
sum_n = 0
n = 1
while sum_n <= 10 ** 5:
    sum_n += n
    l[sum_n] = n
    n += 1
n = int(input())
if n not in l:
    print('No')
else:
    print('Yes')
    m = l[n]
    print(m+1)
    ans = [[] for _ in range(m+1)]
    min_n = 1
    max_n = 1
    for i in range(1, m+1):
        max_n += i
        for j in range(min_n, max_n):
            ans[j-min_n].append(j)
            ans[i].append(j)
        min_n = max_n
    for i in ans:
        print(*i)
