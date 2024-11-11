for i in range(int(input())):
    n=int(input())
    for i in range(2,29):
        if n%(2**i-1)==0:
            print(n//(2**i-1))
            break