n, c = map(int, input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
overall = 0
lift = 2
answer = [0]
for i in range(n-1):
    noice = min(overall + a[i], overall + b[i] + 2, lift + b[i])
    lift = min(overall + b[i] + 2, lift + b[i])
    overall = noice
    answer.append(overall)
print(*answer)
