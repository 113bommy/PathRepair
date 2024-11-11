def solve(n):
    bits = '{0:06b}'.format(int(n))
    return int('{0}{5}{3}{1}{4}{2}'.format(*list(bits)), 2)

print(solve(input()))