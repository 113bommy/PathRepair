for i in range(int(input())):
    n = int(input())+1
    if n<=9:
        print(0)
    elif n ==10:
        print(1)
    else:
        print(n//10)
        
