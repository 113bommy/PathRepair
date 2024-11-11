for i in range(int(input())):
    a=int(input())
    print((((a+(a%2))*25)//10) if a>6 else 15)