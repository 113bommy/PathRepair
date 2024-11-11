N = int(input())
k = 2
yes_n = (k * (k+1)) // 2
flag = False
while N >= yes_n:
    if N == yes_n:
        flag = True
        break
    k += 1
    yes_n = (k * (k+1)) // 2
if flag:
    ans = []
    max_n = 1
    for i in range(k+1):
        tmp = []
        for j in range(i):
            tmp += [ans[j][i-1]]
        for j in range(k-i):
            tmp += [str(max_n)]
            max_n += 1
        ans += [tmp]
    print('Yes')
    print(k+1)
    for a in ans:
        print(k, ' '.join(a))
else:
    print('No')