#! coding: UTF-8
N,A,B = list(map(int,input().split(" ")))
V = list(map(int,input().split(" ")))
V.sort(reverse=True)
max_avr = sum(V[:A]) / A
a_num = V.count(V[A-1])
a_pos = V[:A].count(V[A-1])

#確率統計nCr
import math
def nCr(n,r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)

if V[0] == V[A-1]:
    cnt = sum(nCr(a_num,i) for i in range(A,min(B,a_num))) 
else:
    cnt = nCr(a_num,a_pos)
print("{0:.10f}".format(max_avr))
print(int(cnt))
