n, m = map(int, input().split())

rows = []*n

for i in range(1,m+1):
    if i%2 == 1:
        rows.append("#"*m)
    elif i%4 == 2:
        rows.append("."*(m-1) + "#")
    else:
        rows.append("#" + "."*(m-1))
		
for row in rows:
	print(row)