n = int(input())
P =[]
s = 0
for i in range(n):P.append([int(i) for i in input().split()])
P.append(P[0])
for i in range(n-2):
    s += P[i][0]*P[i+1][1] - P[i][1]*P[i+1][0]
print(abs(s)*0.5)