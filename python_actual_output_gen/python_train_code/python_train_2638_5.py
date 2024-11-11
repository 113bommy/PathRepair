N = int(input())
A = [int(input()) for i in range(N)]
now = 2
count = A[0]-1
for i in range(1,N):
    if A[i] == now:
        now += 1
    elif A[i]%now != 0:
        count += A[i]//now
    else:
        count += (A[i]-1)//(now+1)
print(count)