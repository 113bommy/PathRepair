from fractions import gcd
N = int(input())
Alist = [0]+list(map(int, input().split()))+[0]
Rlist = [0]*(N+2)
Llist = [0]*(N+1)
for i in range(N):
    Llist[i+1] = gcd(Llist[i], Alist[i])
    Rlist[N-i] = gcd(Rlist[N-i+1], Alist[N-i+1])
print(max([gcd(Rlist[i], Llist[i]) for i in range(N)]))
