import sys
a = int(input())
b = list(map(int,input().split()))
if a==1:
     print(b[0])
     sys.exit()
c = [0]*a
for i in range(a):
     c[i]=(b[i]-i-1,b[i])    
ans=0
c.sort()
maxx=0
cc = c[0]
i = 1
while i<a:
     while i<a and c[i][0]==cc:
          maxx+=c[i][1]
          i+=1
     ans=max(ans,maxx)
     maxx=0
     if i<a:cc=c[i][0]
print(ans)
     
     
