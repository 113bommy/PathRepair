digits = list(map(int, input().strip()))
left = digits[:3]; ls = sum(left)
right = digits[3:]; rs = sum(right)

if ls > rs:  
    rs, ls = ls, rs
    left, right = right, left

left.sort()
right.sort(key=lambda x: -x)
# right >= left
i = 0
j = 0
while ls < rs:
    if 9 - left[i] > right[j] - 1:
        ls = ls - left[i] + 9
        i += 1
    else:
        rs = rs - right[j] + 1
        j += 1

print(i + j)


