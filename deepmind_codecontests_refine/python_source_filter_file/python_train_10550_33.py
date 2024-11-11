import math
#n, m = input().split()
#n = int (n)
#m = int (m)
#n, m, k , l= input().split()
#n = int (n)
#m = int (m)
#k = int (k)
#l = int(l)
n = int(input())
#m = int(input())
#s = input()
##t = input()
#a = list(map(char, input().split()))
#a.append('.')
#print(l)
#c = list(map(int, input().split()))
#c = sorted(c)
#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
#f = []
#t = [0]*n
#f = [(int(s1[0]),s1[1]), (int(s2[0]),s2[1]), (int(s3[0]), s3[1])]
#f1 = sorted(t, key = lambda tup: tup[0])

l = 1
u = round(math.sqrt(n))
f = False

while ( l <= u):
    #print(l, u)
    if(l*(l+1)+u*(u+1) < 2*n):
        l += 1
    elif(l*(l+1)+u*(u+1) > 2*n):
        u -= 1
    else:
        f = True
        break
if f:
    print("YES")
else:
    print("NO")
