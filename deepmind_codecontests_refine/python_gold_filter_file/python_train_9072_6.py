
N=int(input())

print(N//2+1)

for i in range(N):
    if i+1<=N//2+1:
        print(1,i+1)
    else:
        print(i+2-(N//2+1),N//2+1)
