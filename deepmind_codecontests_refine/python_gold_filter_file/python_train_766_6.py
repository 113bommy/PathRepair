n = int(input())
l = [int(x) for x in input().split()]
c = 0
for i in range(n):
    if l[i] >= 1:
        c = l[i]
l.sort()
print(1,l[0])
if c == 0:
    print(2,l[1],l[2])
    print(n-3,end = " ")
    for i in range(3,n):
        print(l[i],end = " ")
else:
    print(1,c)
    print(n-2,end = " ")
    for i in range(1,n):
        if l[i] != c:
            print(l[i],end = " ")