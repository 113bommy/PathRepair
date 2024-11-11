lst1=[]
lst2=[]
lst1=[int(i) for i in input().split()]
lst2=[int(i) for i in input().split()]
flag=0
for i in range(0,3):
    if lst1[i]==lst2[i]:
        flag=flag+1

if flag>=2:
    print("YES")
else:
    print("NO")