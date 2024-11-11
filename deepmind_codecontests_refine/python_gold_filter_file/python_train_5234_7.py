def su(x):
    s=0
    for d in x:
        s+=int(d)
    return s
for _ in range(int(input())):
    n,s=input().split()
    s=int(s)
    if su(n)<=s:
        print(0)
    else:
        le=len(n)+1
        ans=["0"]
        for d in n:
            ans.append(d)
        while le>0:
            ans[le-1]="0"
            k=le-1
            fl=1
            while fl==1:
                if ans[k-1]=="9":
                    ans[k-1]="0"
                    k-=1
                else:
                    ans[k-1]=str(int(ans[k-1])+1)
                    fl=0
            if su(ans)<=s:

                st="".join(ans)
                print(int(st)-int(n))
                break
            else:
                le-=1




