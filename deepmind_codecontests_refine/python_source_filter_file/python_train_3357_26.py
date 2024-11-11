import math

for _ in range(int(input())):
    n,k = map(int,input().split())
    # lst = []
    #
    # for i in range(1,n):
    #     lst.append(i)

    r = n-1
    cnt = k//r

    temp = cnt*n

    # for i in range(len(lst)):
    #     lst[i] += temp

    rem = k%r
    if(k>r and rem==0):
        rem = -1
    print(rem + temp)

'''
1 2 3
5 6 7
9 10 11
13 14 15
17 18 19
'''
