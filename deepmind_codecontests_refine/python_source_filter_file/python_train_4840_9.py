n = int(input())
col = []
ans = []
for i in range(n):
    col.append(list(map(int,input().split())))
    ans.append(i)

for i in range(n):
    for j in range(i,n):
        if (col[i][j]== 2 or col[i][j]== 3) and j in ans:
            ans.remove(j)
        if col[i][j]== 1 and i in ans:
            ans.remove(i)

if not ans:
    print('0')
else:
    ans = [str(i+1) for i in ans]
    print(len(ans))
    print(' '.join(ans))