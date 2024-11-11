n=int(input())
if n<2:
    print("No")
else:
    print("Yes")
    
    print(1,n-1)
    print(n,end=" ")
    for i in range(1,n):
        print(i,end=" ")
    