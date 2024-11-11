for _ in range(int(input())):
    n=int(input())
    s=input()
    flag=0
    for i in range(len(s)-1):
        if s[i]=='1' and s[i+1]=='0':
            flag=1
            break
    if flag==0:
        print(s)
    else:
        ans=""
        if s[0]=="1" and s[-1]=="0":
            ans="0"
        elif s[0]=="0" and s[-1]=="0":
            for i in range(len(s)):
                if s[i]=="1":
                    idx_1=i
                    break
            ans=s[0:idx_1]+"0"
        elif s[0]=="1" and s[-1]=="1":
            for i in range(len(s)-1,-1,-1):
                if s[i]=="0":
                    idx_0=i
                    break
            ans=s[idx_0:]
        else:
            for i in range(len(s)):
                if s[i]=="1":
                    idx_1=i
                    break
            for i in range(len(s)-1,-1,-1):
                if s[i]=="0":
                    idx_0=i
                    break
            if idx_1<idx_0:
                ans="0"+s[idx_0:]
            else:
                ans=s
        print(ans)