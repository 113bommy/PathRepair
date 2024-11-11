t=int(input())
l=list(map(int,input().split()))
lst=[]
l.sort()
print(l)
for c in range(t):
    if c%2==0:
        print(l[c],end=" ")
    else:
        lst.append(l[c])
lst.reverse()
print(*lst)