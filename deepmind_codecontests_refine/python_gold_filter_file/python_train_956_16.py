import math
n,m,d=map(int,input().split())
arr=map(int,input().split())
arr=list(arr)
if (n-sum(arr))/(m+1)>d-1 or n<sum(arr):
    print("NO")
else:
    print("YES")
    ans=[]
    for i in range(m):
        ans+=[i+1]*arr[i]
    zeroes=(n-sum(arr))
    e=zeroes/(m+1)
    f=0
    # print(e)
    if e%1!=0:
        f=1//(1-e%1)
    e=math.ceil(e)
    flag=0
    if e>d:
        flag=1
        # e-=1
    # f=e%1
    # c=1//f
    ans=[]
    # print(e)
    i=0
    k=0
    # print(f)
    # print(e,zeroes)
    while  len(ans)<n:

        if i==m-1:
            if zeroes > 0:
                ans += [0] * math.ceil(int(zeroes)/2)
            ans+=[i+1]*arr[i]
            # if zeroes > 0:
            ans += [0] * math.floor(int(zeroes)/2)
            zeroes=0
        else:
            if zeroes>0:

                if k==f-1:

                    ans+=[0]*(math.ceil(e)-1)
                    zeroes -=(math.ceil(e)-1)
                    k = 0
                else:
                    k += 1
                    ans += [0] * (math.ceil(e))
                    zeroes -= (math.ceil(e))


            ans+=[i+1]*arr[i]
            i+=1

            # print(zeroes)
    ans=map(str,ans)
    ans=list(ans)
    # print(len(ans))
    print(" ".join(ans))
