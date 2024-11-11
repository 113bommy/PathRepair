#import random

q=int(input())
A=[]
for i in range(q):
    A.append(list(map(int,input().split())))
    A[i].sort()

#A=[]
#q=10000
#for i in range(q):
#    A.append([random.randint(1,1000000)]*2)
#    A.sort()
#print(A)

for i in range(q):
    a=A[i][0]
    b=A[i][1]
    if a==b :
        ans1=2*(a-1)
    elif a+1==b :
        ans1=2*a-2
    else :
        c=int((a*b-1)**0.5)+2
        while c*c>=a*b :
            c-=1
        #print("c "+str(c))
        if c*(c+1)>=a*b :
            ans1=2*c-2
        else :
            ans1=2*c-1

print(ans1)
