for _ in range(int(input())):
    n = int(input())
    if n%2:
        print('7'+(n-2)//2*'1')
    else:
        print(n//2*'1')