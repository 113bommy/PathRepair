#import math
def ggt(a, b):
    while b != 0:
        c = a % b
        a, b = b, c
    return a

n, m, k = input().split()
n = int (n)
m = int (m)
k = int (k)
#n = int(input())
#m = int(input())
#s = input()
#t = input()
#h = list(map(int, input().split()))
#b = list(map(int, input().split()))
#c = list(map(int, input().split()))

#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
#f = []
#f = [0]*n
#t = [0]*n
#f = [(int(s1[0]),s1[1]), (int(s2[0]),s2[1]), (int(s3[0]), s3[1])]
#f = sorted (f, key = lambda tup: tup[0] )

#h = [""] * n
#f1 = sorted(f, key = lambda tup: tup[0])


#f1 = sorted(t, key = lambda tup: tup[0])
s1, s2, s3 = 0, 0, 0

for i in range(1, 10001):
    if (n % i == 0 and m % i == 0 and (n//i)*(m//i) == k):
        s1 = 4* i
        s2 = 4 *(n//i)
        s3 = 4 *(m//i)
        break;
            
print (s1+s2+s3)
