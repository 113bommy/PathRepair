n, m = map(int, input().split())

dep = [0] * 10004
owe = [0] * 10004

for i in range(m):
    temp = list(map(int, input().split()))
    dep[temp[0]] += temp[2]
    owe[temp[1]] += temp[2]

sum = 0

for i in range(n):
    if dep[i] < owe[i]:
        sum+= owe[i] - dep[i]

print(sum)