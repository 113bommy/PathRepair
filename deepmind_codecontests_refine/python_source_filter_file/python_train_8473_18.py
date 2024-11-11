n = int(input())
x = [0]*8
arr = input().split()
for i in arr:
    x[int(i)]+=1


l = x.copy()
c = 0
group = [[1,2,4], [1,2,6], [1,3,6]]
for g in group:
    while l[g[0]]!=0 and l[g[1]]!=0 and l[g[2]]!=0:
        l[g[0]]-=1
        l[g[1]]-=1
        l[g[2]]-=1
        c+=1

if c==0 or sum(l)==0:
    print(-1)
else:
    l = x.copy()
    group = [[1,2,4], [1,2,6], [1,3,6]]
    for g in group:
        while l[g[0]]!=0 and l[g[1]]!=0 and l[g[2]]!=0:
            print(*g)
            l[g[0]]-=1
            l[g[1]]-=1
            l[g[2]]-=1
