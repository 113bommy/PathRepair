t = int(input())



for i in range(t):
    y = 0
    s,a,b,c =  list(map(int,input().split()))
    k = s // a*c
    y += k*(a+b)
    y += (s - k*a*c)//c
    print(y)
