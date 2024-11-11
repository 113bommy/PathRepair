def paintings_possibility():
    """ This function is a solution to a problem at:
        http://codeforces.com/problemset/problem/675/B
    
        Idea:
        X1 a X2
        b X3 c
        X4 d X5
        Solve:
        X1 + a + b + X3 == a + c + X3 + X4 == 
        == X4 + c + d + X5 == X4 + d + X3+ b

        Note that all numbers have to be in the range of 1..n
    """

    n, a, b, c, d = (int(x) for x in input().split())
    minX1 = max(1-b+c, 1-a+d, 1-a-b+c+d)
    maxX1 = min(n-b+c, n-a+d, n-a-b+c+d)
    if maxX1 >= minX1:
        return n * (maxX1 - minX1 + 1)
    return 0

print(paintings_possibility())
