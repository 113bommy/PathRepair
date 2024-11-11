n=int(input())

if n==2:
    print(0)
    print()
elif n==3:
    print(2)
    print('1 3')
else:
    a=list(range(n-(1-n%2),0,-2))+list(range(2*(n//2),1,-2))
    print(len(a))
    print(' '.join(map(str,a)))