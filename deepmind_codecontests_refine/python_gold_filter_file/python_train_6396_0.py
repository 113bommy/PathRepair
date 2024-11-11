n, k, x = map(int, input().split())
balls = list(map(int, input().split()))

count = 0
for i in range(1, n - 1):
    curr_color = x
    curr_count = 0
    if balls[i] == curr_color and balls[i - 1] == curr_color:
        curr_count = 2
        li = i - 2
        ri = i + 1
        lf = li
        rf = ri
        while lf >= 0 and rf < n and balls[lf] == balls[rf]:
            curr_color = balls[lf]
            while lf >= 0 and balls[lf] == curr_color:
                lf -= 1

            while rf < n and balls[rf] == curr_color:
                rf += 1

            if (li - lf) + (rf - ri) < 3:
                break

            curr_count += (li - lf) + (rf - ri)
            li = lf
            ri = rf
    count = max(count, curr_count)

print(count)
