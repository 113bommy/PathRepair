n, m = list(map(int, input().split()))
l = [[int(i) for i in input().split()] for i in range(n)]
lst = []
for i in range(n):
    for j in range(0,m*2,2):
        lst.append(l[i][j]+l[i][j+1])
print(lst)
for i in range(lst.count(0)):
    lst.remove(0)
print(len(lst))

