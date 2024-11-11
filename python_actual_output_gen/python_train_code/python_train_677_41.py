inp = int(input())
ans=0
primeNo = [i for i in range(1000000) if i%2!=0]
if inp%2==0:
    print(inp//2)
    print("2 "*(inp//2))
else:
    temp =3
    print((inp-temp)//2)
    for i in range((inp-temp)//2+1):
        print("2",end=" ")
    print(temp)