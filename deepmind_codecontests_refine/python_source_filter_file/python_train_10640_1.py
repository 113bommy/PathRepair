t=int(input())
for _ in range(t):
    cnt=0
    ans=0
    ssum=0
    n=int(input())
    mp={}
    s=[]
    for i in range(n):
        nn=str(input())
        s.append(nn)
        mp[nn]=i+1
        if (s[i][0]=='0' and s[i][len(s[i])-1]=='0'):
            cnt += 1
        elif (s[i][0]=='1' and s[i][len(s[i])-1]=='1'):
            ans += 1
        else:
            ssum += 1
    if (cnt>0 and ans>0) and ssum == 0:
        print(-1)
    else:
        can_r=[]
        cannot_r=[]
        for i in range(n):
            ss=s[i]
            ss=ss[::-1]
            if(ss[0]==ss[len(ss)-1]):
                continue
            if ss not in mp:
                can_r.append(s[i])
        ol=0
        lo=0
        for x in can_r:
            if x[0]=='0':
                ol += 1
            else:
                lo += 1
        cnt-min(ol,lo)
        ol -= cnt
        lo -= cnt
        print(max(lo,ol)//2)
        for x in can_r:
            if ol>1 and x[0]=='0' and x[len(x)-1]=='1':
                print(mp[x],end=" ")
                ol -= 2
            elif lo>1 and x[0]=='1' and x[len(x)-1]=='0':
                print(mp[x],end=" ")
                lo -= 2
        