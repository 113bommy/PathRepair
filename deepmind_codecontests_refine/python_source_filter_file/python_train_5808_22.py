n, *x = map(int, input().split())
k = 'ABC'
ans = []
s = [input() for _ in range(n)]
for p in range(n):
    sp = s[p]
    if sp == 'AB':
        i = 0
        j = 1
    elif sp == 'BC':
        i = 1
        j = 2
    else:
        i = 0
        j = 2
    if x[i] == x[j] == 0:
        print('No')
        break
    if x[i] == x[j] and i < n - 1:
        sp1 = s[p + 1]
        if k[i] in si1:
            x[i] += 1
            x[j] -= 1
            ans.append(k[i])
        else:
            x[i] -= 1
            x[j] += 1
            ans.append(k[j])
    elif x[i] < x[j]:
        x[i] += 1
        x[j] -= 1
        ans.append(k[i])
    else:
        x[i] -= 1
        x[j] += 1
        ans.append(k[j])
else:
    print('Yes')
    print(*ans, sep='\n')
