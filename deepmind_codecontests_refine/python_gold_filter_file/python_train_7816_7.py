n=int(input())
s=str(input())
d=set(s)
flag=0
for i in d:
    if(s.count(i)>=2):
        flag=1
        break
if(len(s)==1):
    print('Yes')
elif(flag>0):
    print('Yes')
else:
    print('No')