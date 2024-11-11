t = int(input())
for i in range(t):
    n = int(input())
    if(n<=2):
        print("0")
    else:
        low = n//2
        if(low%2 == 1):
            print(low)
        else:
            print(low - 1)