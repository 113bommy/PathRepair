def pr(s):
    global k
    for i in range(len(s)):
        if (s[i]=='0'):
            s=s[:i]+'o'+s[i+1::]
        elif ('A'<=s[i]<='Z'):
            s=s[:i]+chr(ord(s[i])+k)+s[i+1::]
        if (s[i]=='1' or s[i]=='i'):
            s=s[:i]+'l'+s[i+1::]
    return s
    

s=input()
k=ord('a')-ord('A')
s=pr(s)
for i in range(int(input())):
    p=input()
    ss=pr(p)
    #print(s, ss)
    if pr(p)==s:
        print('No')
        break
else:
    print('Yes')