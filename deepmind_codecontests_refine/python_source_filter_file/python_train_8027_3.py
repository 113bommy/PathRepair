n,k=map(int,input().split())
ar=list(map(int,input().split()))
sigma=sum(ar)
if(sigma%k!=0):
    print('NO')
else:
    cs=0
    st=['0']
    pt=0
    for i in range(len(ar)):
        cs+=ar[i]
        if(cs==(sigma//k)):
            st.append(str(i+1-pt))
            pt=i+1
            cs=0
    if(len(st)==k+1):
        print('YES')
        print(' '.join(st[1:]))
    else:
        print('NO')
        