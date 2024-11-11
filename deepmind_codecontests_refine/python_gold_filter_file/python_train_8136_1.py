n=int(input())
l1=[int(s) for s in input().split()]
l2=[int(s) for s in input().split()]
if n==1:
    print(max(l1[0],l2[0]))
elif n==2:
    print(max(l1[0]+l2[1],l2[0]+l1[0]))
else:
    re1=[0]*n
    re2=[0]*n
    re1[0]=l1[0]
    re2[0]=l2[0]
    re1[1]=re2[0]+l1[1]
    re2[1]=re1[0]+l2[1]
    for i in range(2,n):
        re1[i]=max(re2[i-1],re2[i-2])+l1[i]
        re2[i]=max(re1[i-1],re1[i-2])+l2[i]
    print(max(re1[n-1],re2[n-1]))
