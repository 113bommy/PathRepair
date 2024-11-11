#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

a = []
for i in range(10): a.append(input())
win = {'XXXX.', 'XXX.X', 'XX.XX', 'X.XXX', '.XXXX'}

for i in range(10):
    for j in range(10):
        r, c, d1, d2 = '', '', '', ''
        for k in range(5):
            if j+k < 10:
                r += a[i][j+k]
            if i+k < 10:
                c += a[i+k][j]
            if i+k < 10 and j+k < 10:
                d1 += a[i+k][j+k]
            if i+k < 10 and j-k >= 0:
                d2 += a[i+k][j-k]
        if win.intersection({r, c, d1, d2}) != set():
            print("YES")
            exit()
print("NO")