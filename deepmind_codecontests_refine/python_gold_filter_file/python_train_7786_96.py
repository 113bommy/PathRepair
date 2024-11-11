S = int(input())

Y = -(-S // (10**9))
X = -(S - (Y * (10**9)))

print('0 0 {} 1 {} {}'.format(10**9, X, Y))
