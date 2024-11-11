x = int(input())
cnt = (x//11)*2
k = x%11
if k>=6:
    cnt += 2
else:
    cnt += 1
print(cnt)