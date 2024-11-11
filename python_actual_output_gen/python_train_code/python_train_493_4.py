n, d = input().split()
n = int (n)
d = int (d)
#n = int(input())
#a = list(map(int, input().split()))
#g = list(map(int, input().split()))
#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
# = [""]*n
#f = [0]*n
#t = [0]*n
#f = []


#f1 = sorted(f, key = lambda tup: tup[0])
if (d-n < 2):
    print (-1)
elif (n % 2 == 0):
    print (n, n+1, n+2)
elif (d-n >= 2):
    print (n+1, n+1+1, n+1+2)
else:
    print(-1)
