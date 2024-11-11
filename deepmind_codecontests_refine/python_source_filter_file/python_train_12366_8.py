h,w,k=map(int,input().split())
S=[]
for i in range(h):
    s=int(input(),2)
    S.append(s)
ans=h+w-2
for i in range(2**(h-1)):
    flag=False
    now=0 #区切った数
    cnt=0 #1の数
    y=0
    for j in range(h-1):
        if (i>>j)&1:
            y+=1
    C=[0]*(y+1) #1の数保存配列
    for x in range(w):
        T=[] #現在の列での1の数保存配列
        for j in range(h):      
            cnt+=(S[j]>>x)&1
            if cnt>k:
                flag=True
                break
            if (i>>j)&1: #横の区切り判定
                T.append(cnt)
                cnt=0
            if j==h-1: #最後の列
                T.append(cnt)
                cnt=0
        if flag:
            break
        for j in range(len(C)): #それぞれのブロックに対して
            if C[j]+T[j]>k:
                now+=1
                C=T
                break
            else:
                C[j]+=T[j]
    if flag:
        break
    ans=min(ans,now+y)
print(ans)