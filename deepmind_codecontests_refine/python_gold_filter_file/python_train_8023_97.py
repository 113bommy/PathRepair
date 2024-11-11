a, b = [int(x) for x in input().split()]
print('a {0} b'.format('<' if a < b else '>' if a > b else '=='))