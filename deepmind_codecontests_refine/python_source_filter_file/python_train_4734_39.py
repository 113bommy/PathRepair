s = input()
flag = 0 
for i in range (0,len(s)) :
    if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='y') :
        flag=1
    elif(s[i]=='E' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U' or s[i]=='Y'):
        flag=1
    elif((s[i]>='a' and s[i]<='z') or(s[i]>='A' and s[i]<='Z')) :
        flag=0
if(flag):
    print("YES")
else :
    print("NO")
