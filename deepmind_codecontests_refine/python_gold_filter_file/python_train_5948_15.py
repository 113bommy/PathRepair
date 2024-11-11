from math import sqrt,ceil
n = int(input())
t = input()
x = ''
start = 0
for i in range(int(sqrt(2*n))):
    x+=t[start+i]
    start+=i
print(x)
