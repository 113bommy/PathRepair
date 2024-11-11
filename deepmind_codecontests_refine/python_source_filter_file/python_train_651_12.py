for _ in range(int(input())):
    n = int(input())
    if n==1: print("2");continue
    for i in range(4*n,2*n+3,-2):
        if i%2==0: print(i,end=" ")
    print()