import math
n,k = map(int, input().strip().split(' '))
s='abcdefghijklmnopqrstuvwxyz'
if k>n:
    print(-1)
elif k==1 and n!=1:
    print(-1)
elif k==n:
    print(s[:k])
else:
    p=n-k
    s1='ab'*(p//2+1)
    print('ab'+s1[:p]+s[2:k])

        
                
