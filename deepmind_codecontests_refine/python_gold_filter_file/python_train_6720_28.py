'''
Created on Aug 4, 2016

@author: Md. Rezwanul Haque
'''

n = int(input())
M = 0
C = 0
D = 0
for _ in range(n):
    a,b = map(int, input().split())
    if(a>b):
        M+=1
    elif a<b:
        C+=1
if M>C:
    print('Mishka')
elif C>M:
    print('Chris')
elif C == M:
    print('Friendship is magic!^^')
        