n = int(input())
v = [0 for i in range(2006)] 
 
ans = 0
for i in range(n):
    s = input().split()
    x = int(s[1])
    if s[0] == 'win':
        v[x] = ans + x**2
    else:
        ans = max(ans,v[x])
 
print(ans)