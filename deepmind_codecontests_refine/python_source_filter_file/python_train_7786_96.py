S = int(input())

Y = -(-S // (10**18))
X = -(S - (Y * (10**18)))

print('0 0 {} 1 {} {}'.format(10**18, Y, X))
