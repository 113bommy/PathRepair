s=input()
count1=0
count2=0
for i in range(len(s)):
    if(ord(s[i])>=97 and ord(s[i])<122):
        count1=count1+1
    elif(ord(s[i])>=65 and ord(s[i])<90):
        count2=count2+1

if(count1>=count2):
    s=s.lower()
else:
    s=s.upper()
print(s)
