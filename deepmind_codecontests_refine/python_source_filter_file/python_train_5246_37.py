#import math
#n, m = input().split()
#n = int (n)
#m = int (m)
#n, m, k = input().split()
#n = int (n)
#m = int (m)
#k = int (k)
n = int(input())
#m = int(input())
#s = input()
##t = input()
#a = list(map(char, input().split()))
#a.append('.')
#print(l)
#c = list(map(int, input().split()))
a = input()
a += "."
#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
#f = []
#t = [0]*n
#f = [(int(s1[0]),s1[1]), (int(s2[0]),s2[1]), (int(s3[0]), s3[1])]
#f1 = sorted(t, key = lambda tup: tup[0])
fR = -1
sR = -1
fL = -1
sL = -1
for i in range(n):
    if (a[i] == '.'):
        continue
    if (a[i] == 'R' and fR == -1):
        fR = i+1
    if (a[i] == 'R' and a[i+1] == '.'):
        sR = i+1
    if (a[i] == 'L' and fL == -1):
        fL = i+1
    if (a[i] == 'L' and a[i+1] == '.'):
        sL = i+1
if(fL == -1):
    print(fR, sR)
elif (fR == -1):
    print(sL, fL)
else:
    print(fR, fL)
    
