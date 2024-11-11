n = list(map(int , input().split(" ")))
if(n[1]-n[2]>1):
    print("<<" , end=" ")
for i in range(1 , n[0] ):
    if(i == n[1]):
        print("(" ,i , end="" , sep="")
    if(i >= n[1]-n[2] and i<=n[1]+n[2] and i!= n[1]):
        print(i , end=" ")
    if(i ==n[1]):
        print(")" , end=" ")
if(n[1]+n[2]<n[0]):
    print(">>")