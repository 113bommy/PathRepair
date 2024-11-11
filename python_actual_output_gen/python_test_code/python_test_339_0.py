n= int(input())
if n & 1:
    p = [*range(5)]
    for i in p:
        print(i,end=' ')
    print()
    for i in p:
        print(i,end=' ')
    print()
    for i in p:
        print((2*i)%n,end=' ')
else:
    print(-1)
