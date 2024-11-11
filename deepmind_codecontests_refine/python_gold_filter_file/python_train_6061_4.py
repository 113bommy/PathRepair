test = int(input())

for _ in range(test):
    n = int(input())
    if n%2==0:
        n//=2
        print('1'*n)
    else:
        print(7, end='')
        n//=2
        n-=1
        print('1'*n)

