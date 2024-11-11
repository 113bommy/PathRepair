N = int(input())
A = []
B = []
for _ in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

if(A == B):
    print(1)
    exit()

ans = sum(A)
dis = 10**10
for a, b in zip(A, B):
    if a > b:
        dis = min(dis, b)
print(ans - dis)
