for _ in range(int(input())):
    n,a,b=map(int,input().split())
    s=''
    for i in range(b):
        s+=chr(95+i)
    s=s*(n//b)
    s=s+s[:(n-n//b)]
    print(s)