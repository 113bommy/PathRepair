str1=input()
str2=str1.upper()
n=0
for i in range(1,len(str1)):
    if str1[i]==str2[i]:
        n=0
    else:
        n=1
        break
if n==0:
    print(str1.capitalize())
else:
    print(str2)
