for t in range(int(input())):
    n = int(input())
    arr=input()
    if(len(arr)%2!=0):
        res=2
        for i in range(0,len(arr),2):
            if(int(arr[i])%2!=0):
                res=1
                break
    else :
        res=1
        for i in range(1,len(arr),2):
            if(int(arr[i])%2==0):
                res=2
                break
                
    print(res)
