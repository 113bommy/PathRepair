n, k = map(int, input().split())
table = []
k -= 1
for i in range(n):
    p, t = map(int, input().split())
    table.append([p, t])
table = list(sorted(table, key = lambda x: (-x[0], -x[1])))
i = k-1
c = 1
while(i>=0 and table[i][0]==table[k][0] and table[i][1]==table[k][1]):
    c += 1
    i -= 1
i = k+1
while(i < n and table[i][0]==table[k][0] and table[i][1]==table[k][1]):
    c+=1
    i+=1
print(c)