a,b,c=map(int,input().split())
if c%b==0 or c%a==0:
    print("Yes")
elif c<b and c<a:
    print("No")
elif c <b and c >a:
    if c % a==0:
        print("Yes")
    else:
        print("No")
elif c >b and c <a:
    if c%b==0:
        print("Yes")
    else:
        print("No")
else:
    mx=max(a,b)
    mn=min(a,b)
    ch=0
    for i in range(1,(c//mx)+1):
        if (c-(mx*i))%mn==0:
            #print(i,mx)
            ch=1
            break
    if ch:
        print("Yes")
    else:
        print("No")