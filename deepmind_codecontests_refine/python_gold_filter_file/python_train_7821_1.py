n = int(input())
s = list(map(int, input().split()))
x = [0 for _ in range(n)]

j = 0
for i in range(-1, -n-1, -1):
    if i == -1:
        x[i] = s[i]
    else:
        if s[i] < x[i+1]:
            x[i] = s[i]
        else:
            if x[i+1] - 1 > 0:
                x[i] = x[i + 1] - 1
            else:
                break

print(sum(x))