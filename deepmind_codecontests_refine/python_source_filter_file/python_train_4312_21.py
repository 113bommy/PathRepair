from math import *
n=int(input())
li=list(map(int,input().split()))
li1=[]
#print(len(li))
for i in range(0,n-1):
         li1.append([li[i],li[i+1]])
for i in li1:
      i.sort()
li1.sort(key=lambda x:x[0])
ans="no"
for i in range(1,ceil(n/2)+1):
       for j in range(i):
              if(li1[i][0]>li1[j][0] and li1[i][0]<li1[j][1]) and (li1[i][1]>li1[j][1]):
                               ans="yes"               
print(ans)