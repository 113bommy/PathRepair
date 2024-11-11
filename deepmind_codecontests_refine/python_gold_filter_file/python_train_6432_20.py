N = int(input())
X = list(map(int,input().split()))
Ans = 0
M = round(sum(X)/N)
for i in X:
    Ans +=(i-M)**2
print(Ans)