def Count(s, t):
    res = 0
    for i in range(len(s) - len(t) + 1):
        if s[i:i+len(t)] == t:
            res += 1
    return res

s = input()
n = len(s)
p = [0] * (n + 1)
z = [0] * n
ans = [0] * (n + 1)
#Prefix 
for i in range(1, n):
    p[i] = p[i - 1]
    while p[i] > 0 and s[i] != s[p[i]]:
        p[i] = p[p[i] - 1]
            
    if s[i] == s[p[i]]:
        p[i] += 1
#Z func
l = r = 0
for i in range(1, n):
    if i <= r:
        z[i] = min(z[i - l], r - i + 1)
    while i + z[i] < n and s[i + z[i]] == s[z[i]]: z[i] += 1
    
    if i + z[i] - 1 > r:
        l, r = i, i + z[i] - 1


#for i in range(n - 2, -1, -1):
#    ans[i] += ans[i + 1] + count[i + 1]

for i in range(n):
    ans[p[i]] += 1
#print(ans)
for i in range(n - 1, 0, -1):
    ans[p[i - 1]] += ans[i]
   # print(i, ': ', ans) 
output = []
for i in range(n):
    if z[n - i - 1] == i + 1:
        output.append((i, ans[i + 1]))
print(len(output) + 1)
for i in range(len(output)):
    print(output[i][0] + 1, output[i][1] + 1)
print(n, 1)
