n= int(input())
arr = []
for _ in range(n):
    arr.append(list(input()))
ans =[]
for row in range(n):
    for col in range(n):
        if arr[row][col]=='.':
            ans.append((row+1,col+1))

rows = []
cols = []
for i in ans:
    if i[0] not in rows:
        rows.append(i[0])
    if i[0] not in cols:
        cols.append(i[1])
if len(rows)!=n and len(cols)!=n:
    print(-1)
else:

    if len(rows)==n:
        rows = []
        for i in ans:
            if i[1] not in rows:
                print(i[0],i[1])
                rows.append(i[1])
    else :
        cols = []
        for i in ans:
            if i[0] not in cols:
                print(i[0],i[1])
                cols.append(i[1])
