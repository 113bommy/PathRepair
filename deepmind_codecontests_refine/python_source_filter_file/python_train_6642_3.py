i = input()
x = int(i[0:2])
y = int(i[2:4])

def isMM(a):
  return 1 <= a and a <= 12

r = isMM(x) * 2 + isMM(y)

print(["NA", "YYMM", "MMYY", "AMBIGIOUS"][r])