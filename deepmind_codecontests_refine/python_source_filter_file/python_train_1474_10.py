#-- Two Shuffled Sequences
#https://codeforces.com/contest/1144/problem/C

import sys
from functools import reduce
from collections import defaultdict

def shuffled_sequence(ss):

  if len(ss) == 0:
    return 'NO'

  sss = sorted(ss)
  print('[-] Sorted: ', sss)

  ssi   = [] # increasing
  ssi_d = [] # increasing duplicates
  ssd   = [] # decreasing
  ssd_d = [] # decreasing duplicates

  ssi.append(sss[0])
  ssd.append(sss[-1])

  # find both the strictly increasing scenario.
  for s in sss[1:]:
    if s > ssi[-1]:
      ssi.append(s)
    else:
      ssi_d.append(s)
  print('[-] By Increasing: ', ssi, ssi_d)

  for s in list(reversed(sss))[1:]:
    if s < ssd[-1]:
      ssd.append(s)
    else:
      ssd_d.append(s)
  print('[-] By Decreasing: ', ssd, ssd_d)

  # Lets first try to find if remaining of increasing can be arranged in decreasing order.
  if len(set(ssi_d)) == len(ssi_d):
    # We found the solution with increasing sorting. 
    print ('ssi: ', ssd, 'ssi_d:', ssd_d)
    print ('YES')
    if len(ssi_d) == 0 or len(ssi_d) == 1:
      # Solution has found.
      if len(ssi_d) == 0:
        print(0)
        print('')
      else:
        print(1)
        print(ssi_d[0])
    else:
      print (len(ssi_d))
      for s in ssi_d:
        print(s, end=' ') 
      print('')

    print (len(ssi))
    for s in ssi[::-1]:
      print(s, end=' ') 
    print('')

  elif len(set(ssd_d)) == len(ssd_d):
    print ('ssd: ', ssd, 'ssd_d:', ssd_d)
    print ('YES')
    if len(ssd_d) == 0 or len(ssd_d) == 1:
      if len(ssd_d) == 0:
        print(0)
        print('')
      else:
        print(1)
        print(ssd_d[0])
    else:
      print (len(ssd_d))
      for s in ssd_d:
        print(s, end=' ') 
      print('')

    print (len(ssd))
    for s in ssd[::-1]:
      print(s, end=' ') 
    print('')

  else:
    print('NO')
    

def io():
  ''' This function read input from standard input. '''
  totalIns = int(sys.stdin.readline(), 10)
  ss = [] * totalIns

  for i in sys.stdin.readline().strip().split():
    ss.append(int(i, 10))
    
  shuffled_sequence(ss)

if __name__ == "__main__":
  io()
