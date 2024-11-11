str_in=input()
num=[int(x) for x in str_in.split()]
n=int(num[0])
m=int(num[1])
c=0;List=[]
key=0 #异常标记

#输入浇水信息
for c in range(m):
    str_in=input()
    num=[int(x) for x in str_in.split()]
    List.append(num)
#初始化记录列表
List2=[0 for x in range(0,n+1)]
for i in range(m):
    l=List[i][0]
    r=List[i][1]
    for y in range(l,r+1):
        List2[y]=List2[y]+1
for i in range(1,n+1):
    if List2[i]!=1:
        key=1
        print(i,List2[i])
        break
if key==0:print("ok")