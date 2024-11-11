n = int(input())
P =[]
s = 0
for i in range(n):P.append([int(i) for i in input().split()])
P.append(P[0])
for i in range(n):
    a = P[i][0] ; b = P[i][1]; c = P[i+1][0] ; P[i+1][1]
    s += a * d - b * c
print(abs(s)*0.5)