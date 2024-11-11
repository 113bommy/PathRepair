for _ in range(int(input())):
    n = int(input())
    s = list(input())
    x = ['?']*n
    if x==s:
        ans = ''
        for i in range(n):
            if i%2==0:
                ans+='B'
            else:
                ans+='R'
        print(ans)
    else:
        cnt = 0
        for i in range(n):
            if (s[i]=='R' or s[i]=='B') and cnt>0:
                ind = i-1
                while cnt>0:
                    if s[ind]=='?':
                        if s[ind+1]=='R':
                            s[ind] = 'B'
                        else:
                            s[ind] = 'R'
                        cnt-=1
                    ind-=1
            elif s[i]=='?':
                cnt+=1
        if cnt>0:
            ind = -1
            for i in range(n-1,-1,-1):
                if s[i]!='?':
                    ind = i
                    break
            for i in range(ind,n):
                if s[i] == '?':
                    if s[i-1]=='R':
                        s[i] = 'B'
                    else:
                        s[i] = 'R'
        ans = ''
        for i in s:
            ans+=i
        print(ans)