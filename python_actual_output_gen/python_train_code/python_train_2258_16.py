n = int(input())
order = {0:'a', 1:'a', 2:'b', 3:'b', 4:'c'}
ans = ''
for i in range(n):
    ans += order[i % 5]
print(ans)