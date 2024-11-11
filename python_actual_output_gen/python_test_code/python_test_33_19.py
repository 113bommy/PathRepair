def solve(n):

    map = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]

    rate = 1

    #estimating the row
    while (5 * rate) <= n:
        n -= (5 * rate)
        rate *= 2

    #estimating the column in that row
    return map[int((n-1)/rate)]


if __name__ == "__main__":
    n = int(input())
    print (solve(n))