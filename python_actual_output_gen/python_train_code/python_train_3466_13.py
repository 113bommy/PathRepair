#while True:
s=input()
acnt=[]
cnt=0

for i in range(len(s)):
    if s[i]=='a':
        cnt+=1
    acnt.append(cnt)
suma=acnt[len(acnt)-1]
ans=0
#print(acnt)
for i in range(len(s)):
    bcnt=0
    ac=0
    temp=0
    for j in range(i+1,len(s)):
        if s[j]=='b':
            bcnt+=1
        if s[j]=='a':
            ac+=1
        #print(j,bcnt,ac,end="  ")
        temp=acnt[i]+bcnt+(suma-(acnt[i]+ac))
        if temp>ans:
            ans=temp
    #print()
print(ans)

