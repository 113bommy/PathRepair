for _ in range(int(input())):
    n,k = [int(i) for i in input().split()]
    list1 = [int(i) for i in input().split()]
    list1.sort()
    sum1 = 0
    for i in range(1,n):
        sum1+= (k-list1[i])/list1[0]
    print(int(sum1))