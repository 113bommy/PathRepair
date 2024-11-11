t=int(input())
for _ in range(t):
    s=input()
    i=0
    j=len(s)-1
    l=""
    r=""
    while(i<j):
        if(s[i]==s[j]):
            l+=s[i]
            r+=s[j]
        else:
            break
        i+=1
        j-=1
    rem=s[i:j+1]
    c=""
    for i in range(len(rem)):
        if(rem[0:i+1]==(rem[:i+1])[::-1]) and len(rem[:i+1])>len(c):
            c=rem[:i+1]
    rem=rem[::-1]
    for i in range(len(rem)):
        if(rem[0:i+1]==(rem[:i+1])[::-1]) and len(rem[:i+1])>len(c):
            c=rem[:i+1]
    print(l+c+r[::-1])