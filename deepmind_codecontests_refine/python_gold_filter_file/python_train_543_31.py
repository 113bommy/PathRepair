for _ in range(int(input())):
    n=int(input())
    c=0
    for i in range(1,(n//2)+1):
        c+=8*(i**2)
    print(c)
    