import sys
input = sys.stdin.readline

def common(arr):
  l = 51
  start = 97
  string = ''
  for i in range(l):
    string += 'a'
  print(string)
  previous = string
  for i in range(0, len(arr)):
    string = list(string)
    # print(string)
    #start += 1
    if ord(previous[arr[i] ]) + 1 > 122:
      string[arr[i]] = 'a'
    else:
      string[arr[i]] = chr(ord(previous[arr[i]])+1)
    string = ''.join(string)
    previous = string
    print(string)
        

      


def solution():
  n = int(input())
  arr = list(map(lambda x: int(x), input().split()))
  common(arr)

t = int(input());
for i in range(0, t):
  solution()
  
