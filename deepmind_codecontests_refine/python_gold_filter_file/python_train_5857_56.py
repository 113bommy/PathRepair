for i in range(int(input())):
    a, b  = [int(num) for num in input().split()]
    if a>b:
        c=(b*(b+1))//2
        print(c)
    else:
        c=((a-1)*(a-2))//2 + a
        print(c)