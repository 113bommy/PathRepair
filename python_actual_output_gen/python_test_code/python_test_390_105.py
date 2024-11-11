N=int(input())
P=0
for i in range(N+1):
    if i%3==0 or i%5==0:
        P+=i
print(P)