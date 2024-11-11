n = int(input())
for i in range(0,n):
    x = abs(n//2-i)
    for j in range(0,n):
        if(j>=x and j<n-x):
            print("D", end="")
        else:
            print("*", end="")
    print("\n")