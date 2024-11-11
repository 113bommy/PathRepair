n = int(input())
edges = []
degree = [0]*n
for __ in range (n-1) :
    a = [int(x) for x in input().split()]
    edges.append(a)
    degree[a[1]-1]+=1
    degree[a[0]-1]+=1
count = n-2
value = 0
if max(degree) == 1 :
    for i in range(n) :
        print(i)
else :
    for i in range (n-1) :
        a=edges[i]
        if degree[a[0]-1] == 1 or degree[a[1]-1] == 1 :
            print(value)
            value+=1
        else :
            print(count)
            count-=1
        