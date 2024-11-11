import sys
# from io import StringIO
#
# sys.stdin = StringIO(open(__file__.replace('.py', '.in')).read())

n = int(input())

if n > 36:
    print(-1)
    sys.exit()

ds = ['8'] * (n // 2)
if n % 2 == 1:
    ds.append('4')

print(int(''.join(ds)))