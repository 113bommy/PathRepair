t = int(input())
for _ in range(t):
    n = int(input())
    if(n==1):
        print(0)
    else:
        k = 1
        y = (k+2)*(k+2)-(k)*(k)
        s = 0
        for j in range(1,int(n/2)+1):
            # print(s,y,k)
            s+=(y*j)
            k+=2
            y=(k+2)*(k+2)-(k)*(k)
        print(s)

