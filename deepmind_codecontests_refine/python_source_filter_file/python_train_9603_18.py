for i in range(int(input())):
    a,b,c,d=map(int ,input().split())
    if c>d:
        f = (a-b+c-d-1)//(c-d)*c
    print(b if a<=b else (-1 if c<d else (b+f)))