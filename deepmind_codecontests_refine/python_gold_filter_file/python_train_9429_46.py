n = int(input())
l = [int(x) for x in input().split()]
l.sort()
assume = False
for x in range(0,n-2):
    if l[x]+l[x+1]>l[x+2]:
        assume = True

if assume:
    print("YES")
else:
    print("NO")