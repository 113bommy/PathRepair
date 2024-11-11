'''
Created on ١٢‏/١٢‏/٢٠١٤

@author: mohamed265
'''
n = int(input())
t = [int(x) for x in input().split()]
slon = -20000000000
tempN = n // 3
temp = 0
for i in range(1, tempN + 1):
    if n % i == 0:
        for j in range(i):
            temp = 0
            for k in range(j, n, i):
                temp += t[k]
            slon = max(slon, temp)
print(slon)
