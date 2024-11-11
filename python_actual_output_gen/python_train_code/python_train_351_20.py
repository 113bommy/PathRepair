n = int(input())
t = [0, ]
t += input().split(' ')
t += '90'
time = 90

for i in range(n + 1):
    t[i+1] = int(t[i+1])
    if t[i+1] - t[i] > 15:
        time = t[i] + 15
        break

print(time)


