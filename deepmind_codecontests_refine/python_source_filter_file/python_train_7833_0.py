import sys
input = sys.stdin.readline

def stringTrans(n, s1, s2):
  s1 = list(s1)
  checkList = {}
  for char in s1:
    if char not in checkList and char <= 't':
      checkList[char] = 1
  # checkList = list(checkList)
  # print(checkList)
  start = 'a'
  end = 't'
  count = 0
  while start < end:
    store = []
    current = None
    replace = ''
    minimum = None
    for i in range(n):
      current = start
      if s1[i] == current:
        if s1[i] < s2[i]:
          store.append(i)
          if minimum == None:
            minimum = s2[i]
          else:
            if s2[i] < minimum:
              minimum = s2[i]
        elif s1[i] > s2[i]:
          return -1
    for i in store:
      if minimum <= s2[i]:
        s1[i] = minimum
      else:
        return -1
    # print(s1)
    if len(store) > 0:
      count += 1
    start = chr(ord(start)+1)
  return count
      


def solution():
  n = int(input())
  s1 = input()
  s2 = input()
  print(stringTrans(n, s1, s2))

t = int(input());
for i in range(0, t):
  solution()
  
