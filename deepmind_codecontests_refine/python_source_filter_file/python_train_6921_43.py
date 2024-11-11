n = int(input())
time = [int(x) for x in input().split()]
time.sort()
count = 1
wait = time[0]
for i in range (1, n):
    if time[i] >= wait:
        count += 1
    wait += time[i]
print(count)