s=input()
z=0
c=0
flag=False
for i in range(len(s)):
    if(s[i]=='1'):
        c+=1
        z=0
    else:
        z+=1
        c=0
    if(z==7 or c==7):
        flag=True
        break
if(flag):
    print("YES")
else:
    print("NO")
        
#print(c)
    