n=int(input())
m=n
arr=[]
if(n>1):
    for i in range(1,n+1):
        m-=i
        if(m<abs(m)):
            m+=i
            arr[len(arr)-1]+=m
            break
        else:
            arr.append(i)
    print(len(arr))
    print(*arr)
else:
    print("1")
    print("1")

