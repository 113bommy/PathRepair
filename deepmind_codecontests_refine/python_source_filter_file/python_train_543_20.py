for i in range(int(input())):
    n = int(input())
    cnt = 1
    sum1 = 0
    if n == 1:
        print(1)
    else:
        for i in range(3,n+1,2):
            edge_count = (i**2) - ((i-2)**2)
            sum1 += (edge_count * cnt)
            cnt += 1
        print(sum1)