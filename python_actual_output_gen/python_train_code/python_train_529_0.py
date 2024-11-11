n, d = list(map(int, input().split()))
x = list(map(int, input().split()))

i = 0
j = i + 2
count = 0

while(j<n):
    # print(x[j] - x[i])
    while(j<n and x[j]-x[i] <= d):
        j += 1
    in_betn = j-i-1
    count += (in_betn * (in_betn - 1) / 2)
    i += 1

print(int(count))