k = int(input())
if(k>36):
    print(-1)
else:
    print("8"*(k//2) + "4"*(k%2))
