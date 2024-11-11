def problem():
    T = int(input())
    while T:
        inp = input().split(' ')
        a = int(inp[0])
        b = int(inp[1])
        n = int(inp[2])
        if n==0:
            print(a)
        elif n==1:
            print(b)
        elif n==2:
            print(a^b)
        else:
            if n%3==0:
                print(b)
            elif n%3==1:
                print(a)
            else:
                print(a^b)
        T = T-1

if __name__=='__main__':
    problem()