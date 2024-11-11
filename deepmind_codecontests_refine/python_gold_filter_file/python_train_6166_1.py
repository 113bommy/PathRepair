n, m = map(int, input().split())
s = [input() for i in range(n)]
used = [0] * 105
ans = []
alone = -1
for i in range(n):
    if(used[i]):
        continue
    for j in range(i+1, n):
        if(used[j]):
            continue
        if(s[i] == s[j][::-1]):
            ans.append([i, j])
            used[i] = 1
            used[j] = 1
            break
for i in range(n):
    if(used[i]):
        continue
    temp = s[i][-(m//2):]
    if(s[i][:(m//2)] == temp[::-1] or m == 1):
        alone = i
        break
if(alone == -1):
    print(len(ans) * 2 * m)
else:
    print(len(ans) * 2 * m + m)
for x in ans:
    print(s[x[0]], end = '')
if(alone != -1):
    print(s[alone], end = '')
for x in ans[::-1]:
    print(s[x[1]], end = '')
print()