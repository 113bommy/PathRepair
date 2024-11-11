N = int(input())
S = []
hoge = 1
i = 0
while hoge <= N:
    S.append([])
    i += 1
    for j in range(i):
        S[-1].append(hoge)
        hoge += 1

if S[-1][-1] == N:
    print("Yes")
else:
    print("No")
    exit()

N = len(S)
print(N+1)

for i in range(N):
    print(N,end = " ")
    x,y = 0,i
    for j in range(i+1):
        x = j
        print(S[y][x],end=" ")
    for j in range(i+1,N):
        y = j
        print(S[y][x],end=" ")
    print()
print(N,end = " ")
for i in S:
    print(i[-1],end = " ")
print()