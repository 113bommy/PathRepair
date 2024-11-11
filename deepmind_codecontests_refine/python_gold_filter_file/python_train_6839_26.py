n,k=[int(x)for x in input().rstrip().split()]
a=[int(x)for x in input().rstrip().split()]
b=list(set(a))
if len(b)>=k:
    print("YES")
    for i in range(0,k):
        print(a.index(b[i])+1,end=" ")
else:
    print("NO")

