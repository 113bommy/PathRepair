for i in range(int(input())):
    s=input()
    l=list(s)
    c=0
    ans=""
    if l.count("1")==len(l) or l.count("0")==len(l):
        c=1
        
    if len(l)<3:
        print(s)
    else:
        if c==1:
            print(s)
        else:
            for i in range(len(l)-1):
                if l[i]==l[i+1]:
                    if l[i]=="0":
                        ans+=(l[i]+"1")
                    else:
                        ans+=(l[i]+"0")
                else:
                    ans+=l[i]
            ans+=l[i+1]
            if len(ans)%2!=0:
                if l[0]=="0":
                    ans+="1"
                else:
                    ans+="0"
                
            print(ans)