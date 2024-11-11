"""
Codeforces
6C - Alice, Bob and Chocolate
http://codeforces.com/contest/6/problem/C

Héctor González Belver
../07/2018
"""
import sys
import itertools  

def main():
  bars = int(sys.stdin.readline().strip())
  time = list(map(int,sys.stdin.readline().strip().split()))

  half_time = sum(time)/2

  accumulated_Alice = itertools.takewhile(lambda t: t <= half_time, itertools.accumulate(time))
  accumulated_Bob = itertools.takewhile(lambda t: t <= half_time, itertools.accumulate(time[::-1]))

  try:
    bars_Alice, time_Alice = list(enumerate(accumulated_Alice, start=1))[-1]
  except IndexError:
    bars_Alice, time_Alice = 0, 0
    
  try:  
    bars_Bob, time_Bob = list(enumerate(accumulated_Bob, start=1))[-1]
  except IndexError:
    bars_Bob, time_Bob = 0, 0
  
  if bars_Alice == bars - 1 - bars_Bob:
    if time_Alice <= time_Bob:
      bars_Alice += 1
    else:
      bars_Bob += 1
  
  sys.stdout.write(str(bars_Alice) + '\n')
  sys.stdout.write(str(bars_Bob) + '\n')

if __name__ == '__main__': 
  main()