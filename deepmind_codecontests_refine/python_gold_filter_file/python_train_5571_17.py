# https://codeforces.com/problemset/problem/602/B
n = int(input())
a = list(map(int, input().split()))
D = [0] * n
D[0] = 1
scope = [a[0]]

for i in range(1, n):
    # print(i, a[i], scope)
    if a[i] in scope:
        D[i] = D[i-1] + 1
    else:
        if len(scope) == 1:
            scope.append(a[i])
            D[i] = D[i-1] + 1
        elif len(scope) == 2:
            del scope[:]
            scope.append(a[i-1])
            scope.append(a[i])
            j = i-1
            while j >= 0:
                if a[j] in scope:
                    D[i] += 1
                    j -= 1
                else:
                    D[i] += 1
                    break

print(max(D))
