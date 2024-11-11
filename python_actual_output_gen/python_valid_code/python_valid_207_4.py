n=int(input())
list1=[]
if n<=1:
    print("-1")
if n>1:
    i=1
    while i<=n:
        list1.append(i+1)
        list1.append(i)
        i=i+2
for i in list1:
    print(i,end=" ")