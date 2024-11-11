for _ in range(int(input())):
    a,b,c=list(map(int,input().split()))
    while a//2+10<a-10 and b>0:
        a=a//2+10
        b-=1
    while c>0:
        a=a-10
        c-=1
    print('YES' if a<=0 else 'NO')