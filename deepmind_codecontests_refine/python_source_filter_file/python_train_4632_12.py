import sys
n,k,p,x,y = map(int, input().split())
a = list(map(int, input().split()))
cnt = (n+1)//2 -1
sm = sum(a)
rest = n - k
for i in range(0,len(a)):
    if a[i] < y:
        cnt-=1
        
   
if sm + k > x:
    print(-1)
    sys.exit()

if cnt < 0:
    print(-1)
    sys.exit()
if sm + cnt + (rest - cnt) * y  > x:
    print(-1)
    sys.exit()

a= [y]*(rest - cnt)+[1]*cnt
for i in range(0, rest):
     print(a[i], end = ' ')
