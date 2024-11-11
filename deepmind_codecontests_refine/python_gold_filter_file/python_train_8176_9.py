def fun(s):
    k=0
    for i in s:
        if(i!="?" and s.find(i)!=s.rfind(i)):
            return 0
    for i in s:
        if(i=="?"):
            for j in range(ord('A'),ord('Z')+1):
                if(s.find(chr(j))==-1):
                    s=s[:s.find(i)]+chr(j)+s[s.find(i)+1:]
                    break
    return s
S=input()
if(S.__len__()<26):
    print(-1)
else:
    i=0
    for i in range(S.__len__()-25):
        buf=fun(S[i:i+26])
        if(buf!=0):
            for j in range(0,i):
                if(S[j]=='?'):
                    print('A',end="")
                else:
                    print(S[j],end="")
            print(fun(S[i:i+26]),end="")
            for j in range(i+26,S.__len__()):
                if (S[j] == '?'):
                    print('A',end="")
                else:
                    print(S[j],end="")
            exit()
    print(-1)