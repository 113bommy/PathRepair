N, M = map(int, input().split())
X, Y = [], []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
mx = max(X)
Y.sort()
r = 0
for y in Y[::-1]:
    if y < mx: break
    r+=1
    M -= y
    if M < 0: break
if M > 0: r += -(-M//mx)
print(r)
