q= int(input())

while q > 0:
    q -= 1
    n=int(input())
    
    buy=0
    if n == 2:
        buy=1
    elif n == 3:
        buy=2
    else:
        if n % 2 ==0:
            buy=0
        else:
            buy=1
    print(buy)