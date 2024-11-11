def solve(s):
  s = sorted(s, reverse=True)
  res = s[0]
  c = s[0]
  for i in range(1,len(s)):
    if s[i] == c:
      res += s[i]
    else:
      return res
def main():
  s = input()
  print(solve(s))

main()
