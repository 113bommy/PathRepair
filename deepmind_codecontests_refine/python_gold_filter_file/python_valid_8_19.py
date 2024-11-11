n = int(input())
while(n):
    n-=1;
    p = int(input())
    p1 = 1 if p%3==1 else 0
    p2 = 1 if p%3==2 else 0
    print(p//3 + p1, p//3 + p2 )
