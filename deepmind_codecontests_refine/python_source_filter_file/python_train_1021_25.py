h, w = map(int, input().split())
s = []
for _ in range(w):
    s.append(input())
ans = ((i < h-1 and s[i+1][j] == '#') or (i > 0 and s[i-1][j] == '#') or (j > 0 and s[i][j-1] == '#') or (j < w-1 and s[i][j+1] == '#') for i in range(h) for j in range(w) if s[i][j] == '#')
if False in ans:
    print("No")
else:
    print("Yes")