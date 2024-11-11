A=[1,1,2,6]
for i in range(4,21):
    A+=[A[-1]*i]
N=int(input())
print(A[N]//(A[N//2]**2))