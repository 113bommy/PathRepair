while 1:
    x=int(input())
    if x==0:
        break
    y=0
    for i in range(2,50):
        if x//i - i//2<0:
            break
        if i%2==0:
            if x/i-x//i==0.5:
                y+=1
        else:
            if x%i==0:
                y+=1
    print(y)