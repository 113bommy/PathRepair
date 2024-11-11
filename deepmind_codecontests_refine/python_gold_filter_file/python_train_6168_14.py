import math
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    s=input()
    ss=''.join(sorted(s))
    if k==1:
        print(ss)
    elif len(set(s))==1:
        print(s[0]*(int(math.ceil(len(s)/k))))
    else:
        dic={}
        for i in ss:
            if i in dic:
                dic[i]=dic[i]+1
            else:
                dic[i]=1
        if ss.count(ss[0])<k:
            for i in dic:
                if dic[i]>=k:
                    print(i)
                    break
                else:
                    k=k-dic[i]
        elif ss.count(ss[0])>k:
            print(ss[k-1:n])
        elif ss.count(ss[0])==k:
            if len(set(ss[k-1:n]))==2:
                print(ss[k-1]+ss[-1]*(int(math.ceil(dic[ss[-1]]/k))))
            else:
                print(ss[k - 1:n])

