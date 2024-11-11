def to_list(s):
    return list(map(lambda x: int(x), s.split(' ')))

def solve(a):
    max_count = 1
    for i in range(len(a)):
        j = i-1
        k = i+1
        l_count = 0
        r_count = 0
        while (j >= 0):
            if (a[j] <= a[i]):
                l_count += 1
                j -= 1
            else:
                break
        while (k < len(a)):
            if (a[k] <= a[i]):
                r_count += 1
                k += 1
            else:
                break
        count = l_count + r_count + 1
        if count > max_count:
            max_count = count
    return str(max_count)

n = int(input())
a = to_list(input())
print(solve(a))