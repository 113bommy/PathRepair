for _ in range(int(input())):
    x=int(input())
    i=-1
    while x>=0:
        i+=1
        k=(2**i)-1
        x-=k*(k+1)/2
    print(i)