n, m, k = input().split()
n = int (n)
m = int (m)
k = int (k)
#n = int(input())
#a = list(map(int, input().split()))
#g = list(map(int, input().split()))
#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
# = [""]*n
#f = [0]*n
#t = [0]*n
#f = []

#h = [""] * n
#f1 = sorted(f, key = lambda tup: tup[0])

#f1 = sorted(t, key = lambda tup: tup[0])
a = [0]*m
for i in range (m):
    a[i] = int(input())
    
f = int(input())
c = 0
for i in range (m):
    cu = f ^ a[i]
    count = 0
    while cu > 0:
        if (cu & 1 == 1): count += 1
        cu >>= 1
    if count <= k:
        #print (i)
        c += 1
print(c)
