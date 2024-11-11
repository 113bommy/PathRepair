def kth(ref_lis,c_list):
    c=1
    for i in c_list:
        ref_lis[i]=c
        c+=1


for test in range(int(input())):
    n,k=map(int,input().split())
    st=list(input().split())
    dic={}
    for i in range(n):
        if dic.get(st[i],-1)==-1:
            dic[st[i]]=[i]
        elif len(dic[st[i]])<k:
            dic[st[i]].append(i)
    ans=[0]*n
    nls=[]
    for itm in dic.values():
        if len(itm)==k:
            kth(ans,itm)
        else:
            nls.extend(itm)
    p=(len(nls)//k)*k
    c=1
    for i in range(p):
        if i%k==0:
            ans[nls[i]]=k
        else:
            ans[nls[i]]=(i%k)

    print(*ans)