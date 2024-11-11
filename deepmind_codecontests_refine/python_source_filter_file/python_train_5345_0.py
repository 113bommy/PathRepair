s1=input()
s2=input()
count=0
for i in range(min(len(s1),len(s2))):
    if s1[i]!=s2[i]:
        count+=1
if count==2:
    if set(s1)==set(s2):
        print("YES")
    else:
        print("No")
else:
    print("NO")
               