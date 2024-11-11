input()
X = list(map(int, input().split()))
MIN = min(X)
if MIN == 1:
    print(1)
    exit()
for i in range(len(X)):
    if X[0] % MIN != 0:
        print(-1)
        exit()
print(MIN)

# UB_CodeForces
# Advice: Love everyone in the world
# Location: Where I belong to
# Caption: Happy with family
