input()
X = sorted(set(map(int, input().split())))
if len(X) > 3:
    for i in range(len(X) - 2):
        if X[i + 2] - X[i] == 2:
            print("YES")
            exit()
print("NO")
