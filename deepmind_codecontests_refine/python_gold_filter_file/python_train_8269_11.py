#n, d = input().split()
#n = int (n)
#d = int (d)
n = int(input())
#h = list(map(int, input().split()))
#g = list(map(int, input().split()))
#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
# = [""]*n
#f = [0]*n
#t = [0]*n
f = []
for i in range (n):
    a, b = input().split()
    f.append ((int(a),int(b)))
f1 = sorted(f, key = lambda tup: tup[0])
f2 = sorted(f, key = lambda tup: tup[1])
b = False
for i in range (n):
    if (f1[i] != f2[i]):
        b = True
        break

if (not b):
    print("Poor Alex")
else:
    print("Happy Alex")
        
        

