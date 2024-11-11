n,a,b,c = map(int, input().split())
s = [input() for _ in range(n)]

d = {'A':a,'B':b,'C':c}

ans = ['Yes']

for i in range(n):
    if d[s[i][0]] == 0 and d[s[i][1]] == 0:
        print('No')
        exit()
    if d[s[i][0]] == 1 and d[s[i][1]] == 1 and n > 1:
        d[s[i][0]] = 2
        d[s[i][1]] = 0
        if d[s[i+1][0]] == 0 and d[s[i+1][1]] ==0:
            d[s[i][0]] = 0
            d[s[i][1]] = 2
            ans.append(s[i][1])
        else:
            ans.append(s[i][0])
    elif d[s[i][0]] >= d[s[i][1]]:
        d[s[i][0]] = d[s[i][0]] - 1
        d[s[i][1]] = d[s[i][1]] + 1
        ans.append(s[i][1])
    else:
        d[s[i][0]] = d[s[i][0]] + 1
        d[s[i][1]] = d[s[i][1]] - 1
        ans.append(s[i][0])

for i in range(n+1):
    print(ans[i])