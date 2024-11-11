n = int(input())
a = [int(i) for i in input().split()]
if n==1:
    print(1)
elif n==2:
    print(2)
else:
    maxi = 2
    temp = a[0]
    k = 2
    for i in range(1,len(a)-1):
        if temp+a[i]==a[i+1]:
            k+=1
        elif k>maxi:
            maxi=k
            k=0
        else:
            k=0
        temp=a[i]
    if k>maxi:
        maxi=k
    print(maxi)