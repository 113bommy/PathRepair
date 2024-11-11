for i in range(int(input())):
    n = int(input())
    if n<4:
        print("NO")
    else:
        print("YES")
        m = [[],[]]
        for i in range(1,n+1):
            m[i%2] += i,
        m[1][-1] += n//2
        print(*(m[0]+m[1]))