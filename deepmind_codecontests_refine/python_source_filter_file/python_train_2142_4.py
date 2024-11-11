n,k,a,b=map(int,input().split())
if a==b:
    print("GB"*n)
elif a<b:
    if k*(a+1)<b:
        print("NO")
    else:
        #b,a
        ans=[[k,1] for _ in range(a)]+[[k,0]]
        x=k*(a+1)
        #x>=bをx==bにする
        for i in range(a):
            if x==b:break
            if  x-b>=k-1:
                x-=(k-1)
                ans[i][0]=1
            else:
                ans[i][0]-=(x-b)
                break
        tans=[]
        for i in range(a+1):
            tans.append("B"*ans[i][0])
            tans.append("G"*ans[i][1])
        print("".join(tans))
else:
    if k*(b+1)<a:
        print("NO")
    else:
        #a,b
        ans=[[k,1] for _ in range(b)]+[[k,0]]
        x=k*(b+1)
        #x>=aをx==aにする
        for i in range(b):
            if x==a:break
            if  x-a>=k-1:
                x-=(k-1)
                ans[i][0]=1
            else:
                ans[i][0]-=(x-a)
                break
        tans=[]
        for i in range(b+1):
            tans.append("G"*ans[i][0])
            tans.append("B"*ans[i][1])
        print("".join(tans))
