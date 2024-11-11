t=int(input())
for _ in range(t):
    s=input()
    n=len(s)
    if s==s[::-1]:
        print(s)
        continue
    temp=""
    i=0
    flag=0
    for i in range(n//2):
        if s[i]==s[n-i-1]:
            temp=temp+s[i]
        else:
            flag=1
            break
    s=s[i:n-i]
    if flag==0:
        s=""
    
    if s=="":
        s=temp[::-1]
        print(temp+s)
        continue
    nxt=""
    bck=""
    nt=""
    for j in s:
        nt=nt+j 
        if nt==nt[::-1]:
            nxt=nt 
    s=s[::-1]
    nt=""
    for j in s:
        nt=nt+j 
        if nt==nt[::-1]:
            bck=nt 
    if len(nxt)>len(bck):
        s=temp[::-1]
        print(temp+nxt+s)
    else:
        s=temp[::-1]
        print(temp+bck+s)
        
        