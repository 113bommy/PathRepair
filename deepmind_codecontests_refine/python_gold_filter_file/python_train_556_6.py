l=list(map(int,input().split()))
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
s=(sum(l)+sum(l1)+sum(l2))//2
print (s-sum(l),l[1],l[2])
print (l1[0],s-sum(l1),l1[2])
print (l2[0],l2[1],s-sum(l2))