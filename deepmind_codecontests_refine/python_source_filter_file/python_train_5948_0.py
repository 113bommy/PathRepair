from math import sqrt,ceil
n = int(input())
t = input()
x = ''
start = 0
for i in range(int(ceil(sqrt(n)))):
    x+=t[start+i]
    start+=i
print(x)
