for _ in range(int(input())):
        n = int(input())
        if (n%2 == 0):
             a = str("1")*(n//2)
        elif (n == 3):
            a = str("7")
        else:
            a = str("7") + str("1")*((n-3)//2)
        print (a)
               
