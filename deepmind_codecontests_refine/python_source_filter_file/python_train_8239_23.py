n = int(input())
a = [int(x) for x in input().split()]
k = []
l = [1]
m = []
alpha=1
for i in range(1,len(a[1:])+1):
    if a[0]//a[i]<2:
        k.append(a[i])
    else:
        m.append(a[i])
        l.append(i+1)
        alpha+=1
if a[0]+sum(m)<sum(k):
    print(0)
else:
    print(alpha)
    print(*l)