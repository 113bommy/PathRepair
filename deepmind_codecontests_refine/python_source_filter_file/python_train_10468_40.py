'''
Created on Aug 24, 2016

@author: Md. Rezwanul Haque
'''
n = input()
L = [8,5,3]
cnt = 0
if n[0] == 'a' or n[0] == 'h':
    cnt+=1
if n[1] == '1' or n[1] == 8:
    cnt+=1
print(L[cnt])