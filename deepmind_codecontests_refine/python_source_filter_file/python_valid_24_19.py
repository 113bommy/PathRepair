for i in range(int(input())):
    n = int(input())
    if n<9:
        print(0)
    elif n ==9:
        print(1)
    else:
        print(n//10)
        
