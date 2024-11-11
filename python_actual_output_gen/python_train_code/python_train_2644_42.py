n,m = map(int,input().split())
if(n == 0):
    print(1)
else:
    if(m < n / 2):
        print(m)
    else:
        print(n - m)