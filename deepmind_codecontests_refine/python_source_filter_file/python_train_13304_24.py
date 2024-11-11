L,R = map(int,input().split())
A = []
for i in range(min((R-L), 2020)):
    for j in range(i+1, min((R-L+2), 2020)):
        A.append((i+L)*(j+L)%2019)
print(min(A))