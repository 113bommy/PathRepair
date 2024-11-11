t=int(input())
N=list()
A=list()

for _ in range(t):
    N.append(int(input()))
    A.append(list(map(int, input().split())))
for a in A:
    a.sort(reverse=True)
    print(a)
    
    