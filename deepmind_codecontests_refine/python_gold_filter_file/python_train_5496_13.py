M = int(input())
D = 0
S = 0
for i in range(M):
    c,d = map(int,input().split())
    D += d
    S += c*d
print(D-1+(S-1)//9)