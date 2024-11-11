for i in range(int(input())):
    n,k = map(int, input().split())
    l1 = list(map(int,input().split()))
    count  = 0
    l2 = []
    for j in range(len(l1)):
        if l1[j] % 2 != 0:
            count  = count + 1
            l2.append(j)
    if count % 2 == 0:
        if k % 2 == 0 and k <= count:
            print("YES")
            for tt in range(k):
                if tt != k-1:
                    print(l2[tt]+1, end = " ")
                else:
                    print(n)
        else:
            print("NO")
    else:
        if k % 2 != 0 and k <= count:
            print("YES")
            for tt in range(k):
                if tt != k-1:
                    print(l2[tt]+1, end = " ")
                else:
                    print(n)
        else:
            print("NO")