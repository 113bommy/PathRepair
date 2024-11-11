'''
Created on Jan 27, 2015

@author: mohamed265
'''
t = input().split()
n = int(t[0])
m = int(t[1]) 
print(n + m - 1)
for i in range(n):
    print(1, i + 1)
for i in range(1, m):
    print(i + 1, 1)

