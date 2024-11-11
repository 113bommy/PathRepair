while 1:
    n,m=list(map(int,input().split()))
    if n==0 and m==0:break
    l=range(1,1+n)
    st=m-1
    while len(l)!=1:
        del l[st]
        st+=(m-1)
        while 1:
            if st>=len(l):
                st=st-len(l)
            if st<len(l):break  
    print(l[0])

