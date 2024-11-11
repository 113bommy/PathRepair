s=input()
oc=0
zc=0
id2=0
for i in range(len(s)):
    if s[i]=='1': oc+=1
for i in range(len(s)):
    if s[i]=='0':zc+=1
    if s[i]=='2':
        id2=i
        break
for i in range(zc):
    print("0",end="")
for i in range(oc):
    print("1",end="")
for i in range(id2,len(s)):
    if s[i]=='1': continue
    else: 
        print(s[i],end="")
print()