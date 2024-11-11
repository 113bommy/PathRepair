while 1:
    n=int(input())
    if n==0: break
    for _ in range(n):
        a=list(map(int,input().split()))
        c=sum(a)
        if sum(a[:2])/2>=90 or c/3>=80 or 100 in a: b='A'
        elif c/3>=70 or (c/3>=50 and (a[0]>=80 or a[1]>=80)): b='B'
        else: b='C'
        print(b)