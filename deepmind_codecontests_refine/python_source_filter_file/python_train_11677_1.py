import math
import sys
n,m=[int(x) for x in input().split()]
answer=[]
x=math.ceil(n/2)
y=n%2
for i in range(1,math.ceil(n/2)+1):
        if y==1 and i==x:
            for j in range(1,m//2+1):
                 answer.append(str(i)+' '+str(j))
                 answer.append(str(n-i+1)+' '+str(m-j+1))
            answer.append((str(i)+' '+str((math.ceil(m/2)))))
        else:
            for j in range(1,m+1):
                answer.append((str(i)+' '+str(j)))
                answer.append(str(n-i+1)+' '+str(m-j+1))
print("\n".join(answer))
