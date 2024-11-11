import random
from decimal import Decimal
arr = [int(i) for i in input().split()]
H = arr[0]
L = arr[1]
HL = (H**2+L**2)**0.5
#Hl/H
#(l2+h2)/h
print(format((L**2 - H**2)/2*H, '.13f'))