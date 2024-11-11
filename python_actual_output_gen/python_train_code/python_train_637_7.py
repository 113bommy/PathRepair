for _ in range(int(input())):
    n,k=map(int,input().split())
    if n%2==k%2 and n>=k:
        a=[1]*(k-1) + [n-k+1]
        print('YES')
        print(*a)
    elif n%2==0 and k%2!=0 and n>k*2:
        print('YES')
        a = [2]*(k-1) + [n-2*(k-1)]
        print(*a)
    else:
        print('NO')
