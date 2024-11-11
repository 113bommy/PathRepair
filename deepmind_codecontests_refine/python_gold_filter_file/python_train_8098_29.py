N=int(input())

K=0
for i in range(1,N+1):
    K+=len(str(i))%2
print(K)
