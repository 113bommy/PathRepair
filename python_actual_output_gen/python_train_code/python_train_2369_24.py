k=int(input())
if(k<=36):
    if(k%2==0):
        print(8*(k/2))
    else:
        print("8"*(k//2)+1)
else:
    print("-1")