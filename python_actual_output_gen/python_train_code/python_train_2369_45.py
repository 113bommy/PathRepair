k = int(input())
if(k//2>=19):
    print("-1")
elif(k%2==0):
    print("8"*(k//2))
else:
    print("8"*(k//2),end="")
    print("4")