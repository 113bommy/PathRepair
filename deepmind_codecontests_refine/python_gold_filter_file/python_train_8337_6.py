
import math

n,k = map(int,input().strip().split())

t = input()
h = 0
for i in range(1,n):
    if t[i:]==t[:n-i]:
        #print(100)
        h = 1
        break

m = 1
s = t

if not h:
    i = n

while(m<k):
    s = s+t[n-i:]
    m+=1

print(s)
