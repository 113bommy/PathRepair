q=int(input())
q>0
z=int()
list1=[]
for i in range (1,q+1):
    a,b,c=[int(x) for x in input().split()]
    z=(a+b+c)%2
    list1.append(z)
for y in list1:
    print (y)