#import math

n, m = input().split()
n = int (n)
m = int (m)
#n, m, k = input().split()
#n = int (n)
#m = int (m)
#k = int (k)
#n = int(input())
#m = int(input())
#s = input()
#t = input()
#h = list(map(int, input().split()))

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
for i in range(n):
    for j in range(n):
        if i == j:
            print(m, end = " ")
        else:
            print(0, end = " ")
    print()
