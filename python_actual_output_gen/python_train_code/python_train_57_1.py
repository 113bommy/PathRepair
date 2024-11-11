n,m = map(int,input().split())
w = list(map(int,input().split()))
b = list(map(int,input().split()))
when = []

j = n+m
for i in range(n):
    try:
        j = b.index(i+1)
    except:
        pass
    if j != n+m:
        when.append([j,i])
    j = n+m

when = list(sorted(when))
stack = []
for i in range(len(when)):
    stack.append(when[i][1])

count = 0
where = n+m
for i in range(m):
    where = stack.index(b[i]-1)
    for j in range(0,where):
        count += w[stack[j]-1]
    stack = [stack[where]]+stack[:where]+stack[where+1:]

print(count)
