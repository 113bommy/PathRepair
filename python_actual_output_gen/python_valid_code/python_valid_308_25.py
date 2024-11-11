n,m = map(int,input().split())
line = [0] * (m)
for _ in range(n):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    line[a] += 1
    if b<n-1:
        line[b+1] -= 1
zeros = []
if line[0]==0:
    zeros.append(1)

for i in range(1,m):
    line[i] += line[i-1]
    if line[i]==0:
        zeros.append(i+1)

print(len(zeros))
for ele in zeros:
    print(ele,end = " ")