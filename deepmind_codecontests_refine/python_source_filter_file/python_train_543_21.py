for _ in range(int(input())):
    n=int(input())
    s=0
    for i in range(n):
        s+=(2*(n-i)*i + (n-i-1)*(n-i-2))
    print(s)