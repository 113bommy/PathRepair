t = int(input())
while t>0:
    t-=1
    n = int(input())
    a = list(map(int,input().split()))
    s = 0
    t = 0
    for i in a:
        s+=i 
        t^=i 
    print(2)
    print(t,(s+t))