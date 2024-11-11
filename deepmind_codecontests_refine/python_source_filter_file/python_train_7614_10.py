n,m,h = map(int,input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
li = []
for i in range(n):
    temp = [int(x) for x in input().split()]
    li.append(temp)
for i in range(n):
    for j in range(m):
        if(li[i][j] == 1):
            li[i][j] = max(b[i],a[j])
for i in range(n):
    for j in range(m):
        print(li[i][j],end=" ")
    print()