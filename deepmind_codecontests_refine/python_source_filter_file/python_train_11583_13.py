for _ in range(int(input())):
    n,k=map(int,input().split())
    s1='1'+'0'*k+input()+'0'*k+'1'
    print(s1)
    s=[len(x) for x in s1.split('1')]
    print(s)
    i=0
    for x in s:
        count=(x-k)//(1+k)
        if count>=0:
            i+=count
    print(i)