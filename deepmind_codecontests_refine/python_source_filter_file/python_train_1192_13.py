s1="qwertyuiop"
s2="asdfghjkl;"
s3="zxcvbnm,./"
s1=list(s1)
s2=list(s2)
s3=list(s3)
ch=input()
s=input()
s=list(s)
if(ch=='L'):
    for i in range(0,len(s)):
        for j in range(9,0,-1):
            if(s[i]==s1[j]):
                s[i]=s1[j+1]
            elif(s[i]==s2[j]):
                s[i]=s2[j+1]
            elif(s[i]==s3[j]):
                s[i]=s3[j+1]
elif(ch=='R'):
    for i in range(0,len(s)):
        for j in range(0,10):
            if(s[i]==s1[j]):
                s[i]=s1[j-1]
            elif(s[i]==s2[j]):
                s[i]=s2[j-1]
            elif(s[i]==s3[j]):
                s[i]=s3[j-1]
print("".join(s))
    