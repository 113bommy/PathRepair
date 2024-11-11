B = [False]*10005
C = [0]*10005
for i in range(2,10001):
    if not B[i]:
      	for j in range(i+i,10001,i):
          	B[j]=True
for i in range(3,10001,2):
    if not B[i] and not B[(i+1)//2]:
        C[i]+=1
for i in range(3,10001):
    C[i]=C[i]+C[i-1]
    
N = int(input())
for _ in range(N):
    a, b = map(int,input().split())
    print(C[b]-C[a-1])