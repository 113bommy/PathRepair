N,M = map(int,input().split())
for i in range(1,M+1):
    if N-2*i+1>=N//2 or N%2==1:
        print(i,N-i+1)
    else:
        print(i,N-i)