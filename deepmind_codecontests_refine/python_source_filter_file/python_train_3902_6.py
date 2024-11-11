n, m = [int(x) for x in input().split()]
print('\n'.join('#'*m if i % 2 == 0 else ('#' + '.'*(m - 1) if i % 4 == 3 else '.'*(m + 1) + '#') for i in range(n)))