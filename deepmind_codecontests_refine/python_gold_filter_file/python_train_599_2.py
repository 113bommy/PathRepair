def main():
  import sys
  read = sys.stdin.buffer.read
  r = 998244353
  U, S, *A = map(int, read().split())
  import copy
  ans = 0
  f = [0]*3010
  for a in A:
      c = copy.copy(f)
      f = [0]*a+c[:-a]
      f = [x+y for x,y in zip(f,c)]
      f[0] += 1
      f[a] += 1
      ans += f[S]
  ans %= r
  print(ans)
if __name__ == '__main__':
    main()