s=input()
sl=s.split(' ')
s1=sl[0]
s2=sl[1]
i=0
j=0
ans=""
ans+=s1[0]
for i in range(1,len(s1)):
    if s1[i]>=s2[0]:
        break
    else:
        ans+=s1[i]
ans+=s2[0]
print(ans)