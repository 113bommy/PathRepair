if __name__ == "__main__":
    for i in range(int(input())):
        n , a , b = map(int,input().split())
        temp = 1
        check  = False
        while(n >= temp):
            if (n - temp) % b == 0:
                check  = True
            if a != 1:
                temp *= a
            else:
                break    
        if check:
            print("Yes")
        else:
            print("No")            



