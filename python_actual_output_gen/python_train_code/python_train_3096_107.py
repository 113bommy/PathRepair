n=int(input())
l2=[16,2,4,8]
val2=l2[n%4]
l3=[1,3,9,27]
val3=l3[n%4]
val4=0
if n%2==0:
    val4=6
else:
    val4=4
if n==0:
    print(0)
else:
    print((1+val2+val3+val4)%5)


