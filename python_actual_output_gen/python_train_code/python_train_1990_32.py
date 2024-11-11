x = int(input())
def sumDigit(n):
  return sum(int(digit) for digit in str(n))
for y in range(x, 1001):
  if(sumDigit(y)%4 == 0):
    print(y)
    break