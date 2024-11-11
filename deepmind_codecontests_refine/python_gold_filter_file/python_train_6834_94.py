k = int(input())
if((k+1)//2>18):
    print("-1")
elif(k%2==0):
    print("8"*(k//2))
else:
    print("8"*(k//2),end="")
    print("4")