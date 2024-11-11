n=int(input())
s1=input()
s2=input()
if n==1:
    print(3)
    exit()
s=""
i=0
while i<n:
    if s1[i]==s2[i]:
        s+="1"
        i+=1
    else:
        s+="2"
        i+=2
ans=0
if s[0]=="1":
    ans+=3
else:
    ans+=6
before=s[0]
for j in range(1,len(s)):
    if before=="1":
        if s[j]=="1":
            ans*=2
        else:
            ans*=2
    else:
        if s[j]=="2":
            ans*=3
    before=s[j]
print(ans%(10**7+9))
