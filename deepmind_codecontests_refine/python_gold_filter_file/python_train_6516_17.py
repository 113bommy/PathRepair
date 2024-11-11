n = int(input())
order = {0:'a', 1:'a', 2:'b', 3:'b'}
ans = ''
for i in range(n):
    ans += order[i % 4]
print(ans)