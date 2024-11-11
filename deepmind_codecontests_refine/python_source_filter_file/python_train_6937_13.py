res=0
str=input().split()
if int(str[2])>1 or int(str[3])<int(str[0]):
    if int(str[2])==1:res=abs(int(str[1])-int(str[3]))+1
    if int(str[3])>=int(str[0]):res=abs(int(str[1])-int(str[2]))+1
if int(str[2])>1 and int(str[3]<str[0]):
    res=min(abs(int(str[1])-int(str[3])),abs(int(str[1])-int(str[2])))+abs(int(str[2])-int(str[3]))+2
print(res)