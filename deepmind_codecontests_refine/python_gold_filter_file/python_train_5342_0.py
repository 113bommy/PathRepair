def operation1(p):
    for i in range(0, len(p), 2):
        p[i], p[i+1] = p[i+1], p[i]


def operation2(p):
    return p[len(p)//2:] + p[:len(p) // 2]


n = int(input())
permutations = []
p = list(map(int, input().split()))
sorted_p = [i+1 for i in range(2*n)]
counter = 0
solution = float("inf")
while True:
    permutations.append(p[:])
    if p == sorted_p:
        solution = counter
        break
    if counter % 2 == 0:
        operation1(p)
    else:
        p = operation2(p)

    if p in permutations:
        break
    counter += 1


p = permutations[0]
permutations = []
counter = 0
while True:
    permutations.append(p[:])
    if p == sorted_p:
        solution = min(solution, counter)
        break
    if counter % 2 == 0:
        p = operation2(p)
    else:
        operation1(p)

    if p in permutations:
        break
    counter += 1

if solution != float("inf"):
    print(solution)
else:
    print(-1)