s=input()
q=int(int(s[0])%4==0)
for i in range(1,len(s)):
    if int(s[i-1]+s[i])%4==0:q+=i
    if int(s[i])%4==0:q+=1
print(q)