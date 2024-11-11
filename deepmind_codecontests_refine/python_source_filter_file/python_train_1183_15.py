l = list(map(int,input().strip().split(" ")))
(n,k) = (l[0],l[1])
l = list(map(int,input().strip().split(" ")))
if (k>n):
    print("NO")
else:
    l.sort()
    print(l[n-k],0)

