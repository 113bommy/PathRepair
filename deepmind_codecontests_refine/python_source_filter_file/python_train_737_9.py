import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,input().split()))

if A[0]!=0:
    print(1)
    sys.exit()


MAX=1
for i in range(1,N):
    if A[i]>MAX+1:
        print(i+1)
        sys.exit()
    elif A[i]==MAX+1:
        MAX+=1
    else:
        continue

print(-1)
    
