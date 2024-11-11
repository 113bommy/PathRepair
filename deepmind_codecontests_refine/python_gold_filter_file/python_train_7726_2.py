for _ in range(int(input())):
    n,m=map(int,input().split())
    s=map(int,input().split())
    bit=[0]*100
    s=list(s)
    if sum(s)<n:
        print(-1)
        continue
    for x in s:
        bit[int.bit_length(x)-1]+=1
    ans=0
    pre=None
    now=n%2
    #print(bit[:9])
    #t=[]
    for i in range(90):
        #t.append(now)
        if now==1:
            if bit[i]>0:
                bit[i]-=1
                if bit[i]>0 and pre!=None:
                    ans+=i-pre
                    bit[i]-=1
                    pre=None
            else:
                if pre==None:
                    pre=i
        if now==0:
            if bit[i]>0 and pre!=None:
                ans+=i-pre
                bit[i]-=1
                pre=None
        bit[i+1]+=bit[i]//2
        n//=2
        now=n%2
    #print(t)
    print(ans)