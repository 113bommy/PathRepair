def main():
  n, d, mods = 0, 1, [1]+[0]*2019
  for i in reversed(input()):
    n = (n+int(i)*d)%2019
    d = d*10
    mods[n] += 1
  print(sum([i*(i-1)//2 for i in mods]))
main()
