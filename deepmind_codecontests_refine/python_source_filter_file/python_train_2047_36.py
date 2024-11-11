#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open('input.txt', 'r')
MOD = 998244353
sys.setrecursionlimit(1000000)
 
n, m, k = map(int, input().split())
if k < n:
    print(k+1, 1)
    exit()
k -= n
x = k//(m-1)
y = k%(m-1)
if x%2 == 1:
    print(n-x, m-y)
else:
    print(n-x, m+2)