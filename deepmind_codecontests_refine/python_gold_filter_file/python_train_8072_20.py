n = int(input())
times = list(map(int, input().split()))
a, b = 0, n-1
time_a, time_b = 0, 0
while b >= a:
    if time_a == time_b:
        time_a += times[a]
        a+= 1
    elif time_a > time_b:
        time_b += times[b]
        b -= 1
    else:
        time_a += times[a]
        a += 1
print(a, n-a)


