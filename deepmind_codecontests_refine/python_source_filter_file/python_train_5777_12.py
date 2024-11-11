N = int(input())
Answer = [[1, [1]], [2, [1]], [2, [1, 3]], [4, [3, 1, 4, 2]]]
if N <= 4:
    print(Answer[N - 1][0])
    print(*Answer[N - 1][1])
    exit()
print(N)
print(*list(filter(lambda x: x % 2 == 1, range(1, N + 1))), end=" ")
print(*list(filter(lambda x: x % 2 == 0, range(1, N + 1))), end=" ")

# UB_CodeForces
# Advice: Think Different!!!
# Location: Behind my desk
# Caption: Daily codes
# CodeNumber: 542
