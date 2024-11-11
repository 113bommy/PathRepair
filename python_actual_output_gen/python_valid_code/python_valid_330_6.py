n,m = map(int, input().split())
s = input()
t = input()
ans = 1001
ansp = 0
for i in range(m-n+1):
    matches = 0
    for j in range(n):
        if s[j] == t[i+j]:
            matches+=1
    if n-matches < ans:
        ans = min(n-matches, ans)
        ansp = i
print(ans)
ans1 = []
for j in range(n):
    if s[j] != t[ansp+j]:
        ans1.append(ansp+j+1)
print(' '.join([str(i) for i in ans1]))