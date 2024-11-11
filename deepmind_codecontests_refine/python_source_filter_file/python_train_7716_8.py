from sys import stdin, stdout
import collections
import math

#N = int(input())

N,K = [int(x) for x in stdin.readline().split()]   

b = "{0:b}".format(N)

ones = 0
for bit in b:
    if bit=='1':
        ones += 1

if K<ones or K>N:
    print('NO')
    quit()
else:
    b = [int(x) for x in list(b)]
    
    cur = ones
    for i in range(len(b)-1):
        if b[i]+cur<K:
            cur += b[i]
            b[i+1] += b[i]*2
            b[i] = 0
        else:
            d = K - cur
            b[i+1] += 2*d
            b[i] -= d
            break
        print(cur,b)
        
    print('YES')  
    b = b[::-1]
    for i in range(len(b)):
        for j in range(b[i]):
            print(2**i,end=' ')