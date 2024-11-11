import sys
input = sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
mx=0
cur=[0]*30
for i in range(30):
    cur[i]=[0,0]
for i in a:
    for j in range(30):
        if i==j+1 and cur[j][1]==0:
            cur[j][1]=i
            cur[j][0]-=i
        cur[j][0]+=i
        if i>j+1:
            cur[j][0]=0
            cur[j][1]=0
        if cur[j][0]<0:
            if cur[j][1]==0:
                cur[j][0]=0
            else:
                if cur[j][0]<-j:
                    cur[j][0]=0
                    cur[j][1]=0
        if cur[j][0]>mx and cur[j][1]>0:
            mx=cur[j][0]
print(mx)