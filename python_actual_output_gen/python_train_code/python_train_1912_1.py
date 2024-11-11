N= int(input())
E = [input().split()[2:] for _ in range(N)]
Q = [0]
L = [0] + [-1]*N
flag = [1] + [0]*N
def func(ide):
    global Q
    for i in E[ide]:
        i = int(i) - 1
        if frag[i] != 1:frag[i] = 1;L[i] = L[ide] +1 ;Q.append(i)
    

while Q:top = Q.pop(0);func(top)

for i in range(N):print(i + 1 ,int(L[i]))

