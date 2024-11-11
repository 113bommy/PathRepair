def f():
    a=input()
    b=str(input())
    n=0
    for i in range(len(b)):
        if int(b[i])%2==0:
            n+=i+1
    print(1)
    return 1