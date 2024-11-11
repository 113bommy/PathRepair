H,W = map(int,input().split())
a = []
for i in range(H):
    a.append(list(input()))

lis = [0] * 26
for i in range(H):
    for j in range(W):
        lis[ord(a[i][j]) - ord('a')] += 1

one = 0
two = 0
for i in lis:
    if i % 4 == 2:
        two += 1
    elif i % 4 == 1:
        one += 1
    elif i % 4 == 3:
        two += 1
        one += 1
ans = 'Yes'
if H % 2 == 0 and W % 2 == 0:
    if two > 0 or one > 0:
        ans = 'No'
elif H % 2 == 0 and W % 2 == 1:
    if one > 0 or two > H//2:
        ans = 'No'
elif H % 2 == 1 and W % 2 == 0:
    if one > 0 or two > W//2:
        ans = 'No'
else:
    if one != 1 and two > (H-1 + W-1)//2:
        ans = 'No'
print(ans)
