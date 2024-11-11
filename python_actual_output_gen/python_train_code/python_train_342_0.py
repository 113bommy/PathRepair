N = int(input())
X = list(map(int, input().split()))
Index = N-1
for i in range(N-1 , 1, -1):
    if X[i] <X[i-1]:
        print(i)
        exit()
print(0)


# Hope the best for Ravens member
