M = int(input())
one = input().split().count('1')
two = M - one
n = one + 2 * two
if two > 1 and one > 1:
    print('2 1 ' + '2 ' * (two - 1) + '1 ' * (one - 1))
elif two == 0:
    print('1 ' * one)
else:
    print('2 ' * two)