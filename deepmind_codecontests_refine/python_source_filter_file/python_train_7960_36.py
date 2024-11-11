a=int(input())
s=input()
ans=''
two=0
thr=0
fiv=0
sev=0

for  i in range(len(s)):
    if(s[i]=='2'):
        two+=1
    if(s[i]=='3'):
        thr+=1
        
    if(s[i]=='4'):
        thr+=1
        two+=2
    if(s[i]=='5'):
        fiv+=1
    if(s[i]=='6'):
        fiv+=1
        thr+=1
    if(s[i]=='7'):
        sev+=1
    if(s[i]=='8'):
        sev+=1
        two+=3
    if(s[i]=='9'):
        sev+=1
        two+=3
        thr+=2
ans=''

for i in range(sev):
    ans+='7'
for i in range(fiv):
    ans+='5'
for i in range(thr):
    ans+='3'
for i in range(two):
    ans+='2'
print(ans)
        
