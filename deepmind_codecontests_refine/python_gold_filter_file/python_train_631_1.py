n=int(input())
F=list(map(int,input().split()))
S=list(map(int,input().split()))


SUM=[0]*n
SUM[n-1]=F[n-1]+S[n-1]

for i in range(n-2,-1,-1):
    SUM[i]=SUM[i+1]+F[i]+S[i]


ANS1=0
for i in range(n):
    ANS1+=F[i]*i
    ANS1+=S[i]*(2*n-1-i)

ANS2=0
for i in range(n):
    ANS2+=S[i]*(i+1)
for i in range(1,n):
    ANS2+=F[i]*(2*n-i)


#SABUN[i]=F[i+1]*2+S[i]*(2*n-1-i-i)+S[i+1]*(n-3-i-i)+SUM[2*i]*i


x=ANS1
y=ANS2
ANS=[x,y]


for i in range(0,max(0,n-2),2):
    x=x+F[i+1]*2-S[i]*(2*n-2-i-i)-S[i+1]*(2*n-4-i-i)+SUM[i+2]*2
    y=y-F[i+1]*(2*n-i-i-4)-F[i+2]*(2*n-i-i-4)+SUM[i+2]*2
    ANS.append(x)
    ANS.append(y)
    #print(ANS,i)

print(max(ANS))




