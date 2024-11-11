import sys
import math

n = int(sys.stdin.readline())

a = [['#'] * 11, ['#'] * 11, ['#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'], ['#'] * 11]

k = 0
for i in range(11):
    if(k >= n):
        break
    for j in range(4):
        if(k >= n):
            break
        if(i < 1):
            a[j][i] = 'O'
        else:
            if(j != 2):
                a[j][i] = 'O'
            else:
                k -= 1 
        k += 1        

print("+------------------------+")
print("|" + ".".join(a[0]) + ".|D|)")   
print("|" + ".".join(a[1]) + ".|.|")
print("|" + ".".join(a[2]) + "...|")
print("|" + ".".join(a[3]) + ".|.|)")
print("+------------------------+")