h,w = map(int,input().split())
a = [input() for _ in range(h)]
alpha = [0]*26
for i in range(h):
    for j in range(w):
        alpha[ord(a[i][j])-ord("a")] += 1

ans = "Yes"
odd = 0
cnt = 0

for i in range(26):
    if alpha[i]%2 != 0:
        odd += 1
        alpha[i] -= 1
    if alpha[i]%4 != 0: cnt += 1
    
if odd > 1: ans = "No"
elif h%2 == 1 and w%2 == 1:
    if cnt > h//2+w//2: ans = "No"
elif h%2 == 1:
    if cnt > h//2: ans = "No"
elif w%2 == 1:
    if cnt > w//2: ans = "No"
else:
    if cnt > 0: ans = "No"
print(ans)