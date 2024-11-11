
import math

if __name__ == '__main__':
    n = int(input())
    v = [int(x) for x in input().split()]

    m = max(v)
    s = sum(v)

    # a = m
    # while s > a * (n - 1):
    #     a += 1

    a = max(m, math.ceil(s/n + 1))

    #find min a >= m s.t. s <= a * (n - 1)
    
    print(a)




    # m = 0
    # s = 0
    # for i in range(n):
    #     m = max(m, v[i])
    #     s += v[i]