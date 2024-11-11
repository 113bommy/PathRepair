for i in range(int(input())):
    n=int(input())
    g=[]
    for j in range(n):
        g.append(n-j)
    print(n)
    print(' '.join(map(str,g)))