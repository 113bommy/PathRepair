n=int(input())
if n<=2:
    print(1)
    if n==1:
        print(1)
    else:
        print(1,1)
else:
    arr=[1]*(n+2)
    i=2
    while(i*i<=(n+1)):
        if arr[i]==1:
            j=i
            while(j<=(n+1)//i):
                arr[i*j]=2
                j+=1
        i+=1
    print(2)
    for i in arr[2:]:
        print(i,end=' ')

