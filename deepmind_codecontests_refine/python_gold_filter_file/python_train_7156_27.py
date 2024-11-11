s=str(input())

flag=0
dict1={'A':3,'B':6,'C':13,'.':-1}
for i in range(1,len(s)-1):
    sum=0
    sum=dict1[s[i-1]]+dict1[s[i]]+dict1[s[i+1]]
    if(sum==22):
        flag=1
        break
if(flag==0):
    print("No")
else:
    print("Yes")
