x=False
n=input()
n=int(n)
if n%2==0:
    print(int(n*n/2))
else:
    print(int((n*n-1)/2))
for i in range(n):
    for j in range(n):
        if x==False:
            if j%2==0:
                print(".",end="")
            else:
                print("c", end="")
        if x==True:
            if j%2==0:
                print("c",end="")
            else:
                print(".", end="")
    print("")
    x= not x
    