s = input()
k = int(input())
ans = 1
for v in range(k):
    if  s[v] != "1":
        ans = s[v]
        break
print(ans)