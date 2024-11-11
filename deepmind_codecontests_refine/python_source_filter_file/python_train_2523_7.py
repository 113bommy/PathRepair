def solve(arr, a, b):
    if arr[0] == 0 and arr[1] == 0:
        return 0
    elif arr[0] == 0 and arr[1] != 0:
        return arr[1] * a
    elif arr[0] != 0 and arr[1] == 0:
        return arr[0] * a
    elif arr[0] == arr[1]:
        total_sum = 0
        if b > 2 * a:
            total_sum = total_sum + (2 * a * min(arr))
        elif b < 2 * a:
            total_sum = total_sum + (b * min(arr))
        return total_sum
    else:
        total_sum = abs(arr[0] - arr[1]) * a
        if b >= 2 * a:
            total_sum = total_sum + (2 * a * min(arr))
        elif b < 2 * a:
            total_sum = total_sum + (b * min(arr))
        return total_sum


t = int(input())
output = []
for i in range(t):
    arr1 = [int(arr1) for arr1 in input().split()]
    a, b = [int(a) for a in input().split()]
    output.append(solve(arr1, a, b))
print(*output, sep="\n")

