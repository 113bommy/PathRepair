n = [int(x) for x in input().rstrip().split()][0]
data = [int(x) for x in input().rstrip().split()]

is_found = False
nudges = [0, -1, 1]
last_idx = len(data) - 1

if n <= 1:
    print(0)
    exit()
if n == 3:
    last_idx += 1

result = -1
for s_nudge in nudges:
    for e_nudge in nudges:
        s_val = data[0] + s_nudge
        e_val = data[len(data) - 1] + e_nudge
        if ((e_val - s_val) % (n-1)) == 0:
            num_change = abs(e_nudge) + abs(s_nudge)
            diff = (e_val - s_val) / (n-1)

            val = s_val + diff
            for idx in range(1, last_idx):
                value = data[idx]
                if abs(value - val) == 1:
                    num_change += 1
                elif abs(value - val) > 1:
                    break

                val += diff
                if idx == last_idx - 1:
                    if result == -1 or result > num_change:
                        result = num_change
print(result)
