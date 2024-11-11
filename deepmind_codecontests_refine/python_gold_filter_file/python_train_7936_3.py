for p in range(int(input())):
    n=int(input())
    arr=input().split(" ")
    arr=map(int,arr)
    arr=list(arr)
    sumarr=[]
    su=0
    M=max(arr)
    m=min(arr)
    for i in range(len(arr)):
        su+=arr[i]
        sumarr.append(su)
    # print(sumarr)
    s=set()
    if len(sumarr)>=2:
        s.add(sumarr[1])
    for i in range(1,len(sumarr)):
        for j in range(i-1):

                s.add(sumarr[i])
                ans=sumarr[i]-sumarr[j]
                if ans<=M and ans>=m:
                    s.add(ans)
    ans=0
    # print(s)
    for d in arr:
        if d in s:
            ans+=1
    print(ans)



