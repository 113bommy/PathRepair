N,x = map(int,input().split())
A = sorted(list(map(int,input().split())))
i = 0
while i<N and x>=A[i]:
    x -= A[i]
    i += 1
if x>0:
    i -= 1
print(i)