
n, k = map(int, input().split())
ans = n
b = [str(i) for i in range(k+1)]

for i in range(n):
    nn = input()
    for j in b:
        if j not in nn:
            ans -= 1
            break
print(ans)
