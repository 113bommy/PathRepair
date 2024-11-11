
for _ in range(int(input())):
    n=int(input())
    for i in range(2,n):
        if n%(2**i-1)==0:
            print(int(n/(2**i-1)))
            break