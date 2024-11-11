# cook your dish here
t = int(input())
while t>0:
    n,x,a,b = map(int, input().split())
    #li = list(map(int, input().split()))
    if abs(a-b) + x >n-1:
        print((n-1))
    else:
        print(abs(a-b)+ x)
    t = t-1