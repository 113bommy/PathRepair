s = input()
k = int(input())

ans = 1
for i in range(k):
    if s[i] != '1':
        ans = s[i]
        break
print(ans)