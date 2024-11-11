def main():
    n = int (input())
    t = n;
    A = []
    B = []
    while ( t > 0):
        a,b = map(int,input().split())
        A.append(a)
        B.append(b)
        t = t - 1
    x = 0
    for u in range(n):
        for v in range(n):
            if (A[u] == B[v] and u!=v):
                 x = x + 1
                 break
    print (x)
            
if __name__ == '__main__':
    main()

