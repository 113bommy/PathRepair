(na,nb)=map(int,input().split())
(k,m)=map(int,input().split())

a=(input().split())
b=(input().split())
a=list(map(int,a))
b=list(map(int,b))

temp1=a[:k]
temp2=b[-m:]


if temp1[len(temp1)-1]< temp2[0]:
    print('YES')
else:
    print('NO')
