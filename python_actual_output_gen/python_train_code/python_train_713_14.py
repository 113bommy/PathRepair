n,m,k = [int(x) for x in input().split()]
def solution(n,m,k):
    if 0 <= k < n:
        print("{} 1".format(k+1))
        return
    row = n - (k - n)//(m-1)
    if row % 2: #is odd
        col = 2 + (k - n)%(m-1)
    else:
        col = m - (k - n)%(m-1)
    print("{} {}".format(row, col))


solution(n,m,k)
