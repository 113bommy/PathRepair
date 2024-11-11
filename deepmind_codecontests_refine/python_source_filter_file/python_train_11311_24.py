#! /usr/bin/python3 -s

"""
  1  If a = 0 or b = 0, end the process. Otherwise, go to step 2;
  2  If a ≥ 2·b, then set the value of a to a - 2·b, and repeat step 1. Otherwise, go to step 3;
  3  If b ≥ 2·a, then set the value of b to b - 2·a, and repeat step 1. Otherwise, end the process.
    
"""

def funct_1(a, b):
  if a == 0 or b == 0:
    return [a, b]
  else:
    return funct_2(a,b)

def funct_2(a, b):
  if a >= 2 * b:
    rest = a % b
    coef = (a - rest) / b
    
    if coef % 2 == 0:
      a = rest
    else:
      a = a - ((coef - 1) * b)
      
    return funct_1(a, b)
  else:
    return funct_3(a, b)

def funct_3(a, b):
  if b >= 2 * a:
    rest = b % a
    coef = (b - rest) / a
    
    if coef % 2 == 0:
      b = rest
    else:
      b = b - ((coef - 1) * a)
      
    return funct_1(a, b)
  else:
    return [a, b]

def main():
  [a,b] = [int(x) for x in input("").split()]
  
  if a == 0 or b == 0:
    rpta = funct_1(a, b)
  elif a >= 2 * b:
    rpta = funct_2(a, b)
  elif b >= 2 * a:
    rpta = funct_3(a, b)
  else:
    rpta = [a, b]
      
  print('%d %d' %(rpta[0] , rpta[1]))


main()