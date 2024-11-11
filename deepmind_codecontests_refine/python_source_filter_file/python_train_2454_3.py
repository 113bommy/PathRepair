a = int(input())
b = int(input())
c = int(input())

lowest = (c-(c % 4))
for x in range(lowest, -1, -4):
  if b >= x//2 and c >= x//4:
    print(x + (x//2) + (x//4))
    break