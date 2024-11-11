t=int(input())
for i in range(t):
    n=int(input())
    if n%4==0:
        print("YES")
        arr=[]
        for i in range(1,n+1):
            if i%2==0:
                arr.append(i)
        avh=sum(arr)//len(arr)
        for j in range(1,n+2,2):
            if j!=avh:
                arr.append(j)
        print(arr)
    else:
        print("NO")
