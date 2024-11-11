t=int(input())
for _ in range(t):
    
    n,m=map(int,input().split())
    l=[]
    for i in range(m):
        l.append(chr(97+i))
    n=n//m
    a=n%m
    print(''.join(map(str,(n*l+l[:a-1]))))