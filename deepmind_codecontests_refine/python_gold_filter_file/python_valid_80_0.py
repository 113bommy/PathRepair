for t in range(int(input())):
    n = int(input())
    num = str(input())
    zeros = []
    for i in range(n):
        if num[i] == '0':
            zeros.append(i+1)
    if len(zeros) != 0:
        if zeros[0] <= n//2:
            l1 = zeros[0]
            r1 = l1 + n//2
            l2 = l1+1
            r2 = r1
        else:
            r2 = zeros[-1]
            l2 = r2 - n//2
            l1 = l2
            r1 = r2-1
        print(l2,r2,l1,r1)
    else:
        print(1,n//2,2,1+n//2)