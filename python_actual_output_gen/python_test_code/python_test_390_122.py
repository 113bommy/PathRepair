N=int(input())
P=0
for i in range(N):
    if i%3==0 or i%5==0:
        P+=1
print(P)