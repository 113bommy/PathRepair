num = int(input())
def check(b, items, k):
  for item in items:
    if(abs(int(item) - b) > k):
      return False
  return True

def findMaxB(items, k):
  b = 0
  for item in items:
    curr = int(item) + k
    if(check(curr, items, k)):
      if(b < curr):
        b = curr
  return b
  
for i in range(0, num):
  info = input()
  parsedInfo = info.split(' ')
  k = int(parsedInfo[1])
  items = input()
  parsedItems = items.split(' ')
  print(findMaxB(parsedItems, k))