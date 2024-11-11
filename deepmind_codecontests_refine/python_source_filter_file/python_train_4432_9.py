s = input()
n = int(s[:len(s) - 1])
c = s[len(s) - 1]
d = {"f": 1, "e": 2, 'd': 3, 'c': 6, 'b': 5, 'a': 4}
print(c)
if n % 4 == 1:
      print((n - 1) * 6 // 2 + d[c] + n - 1)
if n % 4 == 3:
      print((n - 3) * 6 // 2 + d[c] + n - 3)
if n % 4 == 2:
      print((n - 2) * 6 // 2 + + n - 2 + 7 + d[c])
if n % 4 == 0:
      print((n - 4) * 6 // 2 + 7 + n - 4 + d[c])