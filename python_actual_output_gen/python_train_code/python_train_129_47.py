#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open('input.txt', 'r')
MOD = 998244353
sys.setrecursionlimit(1000000)
 
n = int(input())
x = list(map(int, input().split()))
a, b = 0, 0
for i in range(n//2):
    a += abs(x[i]-2*i-1)
    b += abs(x[i]-2*i-2)
print(min(a, b))