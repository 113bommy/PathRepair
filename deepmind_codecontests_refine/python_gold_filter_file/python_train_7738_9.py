n, k = map(int, input().split(' '))
#n=int(input())
P = []
for i in range(2, n + 1):
    if all(i % p != 0 for p in P):
        P.append(i)
t=k
for i in range(len(P)-1):
    if P[i]+P[i+1]+1 in P:
        t-=1
if t<=0:
    print("YES")
else:
    print("NO")
    
        