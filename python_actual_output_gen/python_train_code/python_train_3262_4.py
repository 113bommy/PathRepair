import itertools
A, B, C, D = list(input())

op = ['+','-']

for a,b,c in itertools.product(op,op,op):
  x = A + op1 + B + op2 + C + op3 + D
  if(eval(x) == 7):
    print(x + "=7")
    break