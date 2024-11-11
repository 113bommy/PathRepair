t = int(input())

for _ in range(t):

    hello = list(map(int,input().split()))
    n = hello[0]
    x = hello[1]
    y= hello[2]
    m = n-1
    while m!=0:
        if (x-y)%m==0:
            dif = (y-x)//m
            break
        m-=1
    while True:
        if y - dif*(n-1) <1:
            
            y+=dif
            
        else:
            break

    for i in range(n):
        #ans.append(x)
        print(y,end=" ")
        y-=dif
    print()
    
  