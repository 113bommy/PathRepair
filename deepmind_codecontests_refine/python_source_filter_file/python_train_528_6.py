def _1036B(n, m, k):

    n = abs(n)
    m = abs(m)
    if max(n, m) > k:

        return(-1)

    else:

        diagonal_moves = min(m, n)

        if (max(m,n) - min(m, n)) % 2 != 0:
            diagonal_moves += k - diagonal_moves - 1

        else:

            if k - diagonal_moves % 2 == 0:

                diagonal_moves += k - diagonal_moves

            else:

                diagonal_moves += (k- diagonal_moves) - 2

        return(diagonal_moves)

number = int(input())
for index in range(number):

    n,m, k = list(map(lambda x: int(x), input().split()))
    print(_1036B(n, m, k))
