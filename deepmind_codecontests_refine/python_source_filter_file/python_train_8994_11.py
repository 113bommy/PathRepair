n,m=list(map(int,input().split()))
if m==0:
    print("YES")
else:
    s=list(map(int,input().split()))
    s=sorted(s)
    m,c,y=0,1,"YES"
    if "1" in s or n in s:
        y="NO"
    else:
        try:
            for i in s:
                if s[c]-int(i)==1:
                    m+=1
                else:
                    m=0
                if m>1:
                    y="NO"
                c+=1
        except:
            pass
    print(y)