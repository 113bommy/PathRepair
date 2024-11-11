s=input()
s1=s[1:]
count=0
for i in range(len(s1)):
    if ord(s1[i])>=65 and ord(s1[i])<=90:
        count+=1
if count==len(s1):
    if ord(s[0])>=65 and ord(s[0])<=90:
        count+=1
    if count==len(s):
        print(s[0]+s1.lower())
    else:
        print(s[0].upper()+s1.lower())
else:
    print(s)
    
