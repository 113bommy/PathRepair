for q in range(int(input())):
    n=int(input())
    st=input()
    maxm,count,flag=0,0,0
    for i in range(n):
        if st[i]=='A':
            flag=1
            maxm=max(maxm,count)
            count=0
        else:
            if flag==1:
                count+=1
            else:
                continue
    maxm=max(maxm,count)
    print(maxm)