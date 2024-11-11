N = int(input())
if N in [1, 2]:
    print(1)
    print(1)
    exit()
if N == 3:
    print(2)
    print(1, 3)
    exit()
if N==4:
    print(4)
    print(3,1,4,2)
    exit()
print(N)
print(*list(filter(lambda x: x % 2 == 1, range(1, N + 1))), end=" ")
print(*list(filter(lambda x: x % 2 == 0, range(1, N + 1))), end=" ")

# UB_CodeForces
# Advice: Think Different!!!
# Location: Behind my desk
# Caption: Daily codes
# CodeNumber: 542
