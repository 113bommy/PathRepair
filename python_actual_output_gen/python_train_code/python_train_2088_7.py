for _ in range(int(input())):
    n = int(input())
    if n%2:
        print((n-2)//2*'1'+'7')
    else:
        print(n//2*'1')