def solve():
    n = int(input())
    if n%2==0:
        print(n//2)
        return
    for i in range(3, int(n**(0.5))+1):
        if n % i == 0:
            print(((n-i)//2)+1)
            return
    print(1)
solve()
