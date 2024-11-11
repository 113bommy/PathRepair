def get_max(n,l,r):
    max_ans = 0
    i = 0
    while r:
        max_ans += pow(2,i)
        i += 1
        r -= 1
    val = pow(2,i-1)
    while n-i > 0:
        max_ans += val
        i+=1
    return max_ans
def get_min(n,l,r):
    min_val = n - l + 1
    x = n - min_val
    i = 1
    while x:
        min_val += i*2
        i += 1
        x -= 1
    return min_val
n,l,r = map(int, input().split())
print("{} {}".format(get_min(n,l,r),get_max(n,l,r)))
