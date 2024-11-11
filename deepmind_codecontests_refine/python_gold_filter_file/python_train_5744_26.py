n=int(input())

#print(sum(n1))

for i in range(n,1005):
    n1=[int(j) for j in str(i)]
    sn1=sum(n1)
    if sn1%4==0:
        print(i)
        break



    