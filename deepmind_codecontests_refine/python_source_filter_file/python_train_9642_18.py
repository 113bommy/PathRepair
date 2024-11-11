x=int(input())
s=input()
c=0
r=0
for i in range(x-1):
    if(s[i]=="F" and s[i+1]=="S"):
        c+=1
    if(s[i]=="S" and s[i+1]=="F"):
        r+=1
if(c>r or r>c):
    print("YES")
else:
    print("NO")
    