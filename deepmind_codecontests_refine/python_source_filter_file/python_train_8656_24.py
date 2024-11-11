T=int(input())
for _ in range(T):
    n=int(input())
    strng=input().strip()
    
    if (n<11):
        print('NO')
    else:
        if('8' in strng[:n-11]):
            print('YES')
        else:
            print('NO')