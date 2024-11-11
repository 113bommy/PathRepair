
s1=input()
s11=len(s1)
s2=input()
s22=len(s2)
s3=input()
s33=len(s3)
for i in range (0,s11):
    for j in range(0,s33):
   #     print(s1[i],' ',s3[j])
        if s1[i]==s3[j]:
            s3=s3.replace(s1[i],'',1)
            s33 = len(s3)
            flag=1
            break
        else:
            flag=0
    if flag==0:
        print("NO")
        quit()


for i in range (0,s22):
    for j in range(0,s33):
       # print(s1[i],' ',s3[j])
        if s2[i]==s3[j]:
            s3=s3.replace(s2[i],'',1)
            s33 = len(s3)
            flag=1
            break
        else:
            flag=0
    if flag==0:
        print("NO")
        quit()

s33 = len(s3)
if s3!=0:
    print("NO")
else:
    print("YES")
"""
n=input()
print(n.replace('k','',1))

"""