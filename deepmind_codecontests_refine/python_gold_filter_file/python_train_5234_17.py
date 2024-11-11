
for ad in range(int(input())):
    n,s=list(map(int,input().split()))
    x=list(str(n))
    x=list(map(int,x))
    add=sum(x)
    if add<=s:
        print(0)
    else:
        ans=""
        t=0
        c=0
        for i in range(len(x)):
            if c+x[i]<s and t==0:
                c+=x[i]
            elif t==1:
                if i != len(x) - 1:
                    ans += str(9 - x[i])
                else:
                    if x[i] == 0:
                        ans += "0"
                        ans=str(int(ans)+10)
                    else:
                        ans += str(10 - x[i])
            else:
                t=1
                if i!=len(x)-1:
                    ans+=str(9-x[i])
                else:
                    if x[i]==0:
                        ans+="0"
                        ans = str(int(ans) + 10)
                    else:
                        ans+=str(10-x[i])
        print(int(ans))



