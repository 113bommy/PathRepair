t=int(input())
if(1 <= t <= 10**14):
    for i in range(t):
        n= int(input())
        if(1 <= n <= 10**18):
            if(-10*18 <= -(n-1) <= n and n <= 10**18):
                print(-(n-1),n)