B = [False]*100005
C = [0]*100005
for i in range(2,100001):
    if not B[i]:
      	for j in range(i+i,100001,i):
          	B[j]=True
for i in range(3,100001,2):
    if not B[i] and not B[(i+1)//2]:
        C[i]+=1
for i in range(3,100001):
    C[i]=C[i]+C[i-1]
    
N = int(input())
for _ in range(N):
    a, b = map(int,input().split())
    print(C[b]-C[a-1])
