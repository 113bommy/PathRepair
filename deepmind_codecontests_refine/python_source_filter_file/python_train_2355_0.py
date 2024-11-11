from sys import stdin, stdout

class Solve:
  def __init__(self):
    R = stdin.readline
    W = stdout.write
    n, x = map(int, R().split())
    ans = []
    if n == 2 and x == 0:
      W('NO\n')
      return
    elif n == 1:
      W('YES\n%d' % n)
      return
    elif n == 2:
      W('YES\n%d %d' % (0,x))
      return
    ans = ['YES\n']
    xor = 0
    for i in range(1,n-2):
      xor ^= i
      ans.append(str(i) + ' ')
    if xor == x:
      ans += [str(2**17)+' ', str(2**18)+' ',str((2**17)^(2**18))]
    else:
      ans += ['0 ', str(2**17)+' ', str((2**17)^xor^x)]
    W(''.join(ans))

def main():
  s = Solve()
main()
