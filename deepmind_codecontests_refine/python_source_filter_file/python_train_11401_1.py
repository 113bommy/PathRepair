n = int(input())
x = input()

q = []

for y in x:
    q.append(int(y))


# checking the actual score
def get_score(x, y):
    # O(n)
    score = 1
    f = q[x]
    for i in range(x + 1,  y):
        if q[i] != f:
            score += 1
            f = 1 - f
    return score

flip = 1
for i in range(1, n):
    if flip == 1:
        if q[i] == q[i - 1] and (i + 1 == n or q[i] == q[i + 1]):
            flip = 0
            q[i] = 1 - q[i]
    elif flip == 0 and q[i] == q[i-1]:
        q[i] = 1 - q[i]
    else:
        break

print(get_score(0, n))