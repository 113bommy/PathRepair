for i in range(int(input())):
    n=int(input())
    g=[]
    for j in range(n):
        g.append(j+1)
    print(n)
    print(' '.join(map(str,g)))