from math import ceil
n=int(input())
if(n>36):
    print(-1)
else:
    print("8"*(n//2),end="")
    if(n%2==1):
        print("0")