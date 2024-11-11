def solve():
    if b/m > a:
        return a*m
    else:
        cost = 0
        remainder = n-(n//m)*m
        cost += ((n//m)*b)
        if remainder*a > b:
            cost += b
            return cost
        else:
            cost += remainder*a
            return cost

if __name__ == '__main__':
    n, m, a, b = map(int, input().split())
    print(solve())