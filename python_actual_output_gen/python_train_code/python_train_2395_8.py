n1,n2=input().strip().split(" ")
n1,n2=[int(n1),int(n2)]
k,m=input().strip().split(" ")
k,m=[int(k),int(m)]
a=list(map(int,input().strip().split(" ")))
b=list(map(int,input().strip().split(" ")))
a.sort()
b.sort()
pp=a[k-1]
xx=n2-1
for i in range(n2):
    if b[i]>pp:
        xx=i
        break
if (n2-1-xx>=m):
    print("YES")
else:
    print("NO")
