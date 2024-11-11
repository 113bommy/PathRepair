for i in range(int(input())):
    a=int(input())
    print(int((a+(a%2))*2.5) if a>6 else 15)