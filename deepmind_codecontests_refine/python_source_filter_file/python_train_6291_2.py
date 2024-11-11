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
#t = input()
k = list(map(int, input().split()))
m = []
for i in range(n):
    m.append(list(map(int, input().split())))
#print(l)
#c = list(map(int, input().split()))

#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
#f = []
#t = [0]*n
#f = [(int(s1[0]),s1[1]), (int(s2[0]),s2[1]), (int(s3[0]), s3[1])]
#f = sorted (f, key = lambda tup: tup[0] )

#h = [""] * n
#f1 = sorted(f, key = lambda tup: tup[0])


#f1 = sorted(t, key = lambda tup: tup[0])
mi = 100*100+1
for i in range(n):
    s = 0
    for j in range(k[i]):
        s += m[i][j]*5+15
    if k[i] == 0:
        s = 0
    mi = min(mi, s)
    
print(mi)
        

