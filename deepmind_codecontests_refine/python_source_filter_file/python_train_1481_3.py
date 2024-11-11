
n = int(input())
a = [int(x) for x in input().split(" ")]
 
a.sort()
b = pow(2, 30)
while b > 0 and (a[n-1] % b) == a[n - 1]:
    b /= 2
 
b = int(b)
 
if b == 0:
    print(0)
    exit(0)
 
 
def sol(nums, lo, hi, bit):
    bit = int(bit)
    if bit < 1:
        return nums[lo] % 2, 0
    if hi - lo == 0:
        return nums[lo] % (bit * 2), 0
 
    ind = lo
    while ind <= hi and nums[ind] & bit != bit:
        ind += 1
 
    if ind-1 - lo == 0:
        x, maxi = sol(nums, ind, hi, bit / 2)
        return x + bit, maxi
    elif hi - ind < 0:
        x, maxi = sol(nums, lo, ind - 1, bit / 2)
        return x, maxi
    else:
        x_l, maxi_l = sol(nums, lo, ind - 1, bit / 2)
        x_r, maxi_r = sol(nums, ind, hi, bit / 2)
        if maxi_l <= maxi_r:
            return x_l + bit, maxi_l + bit
        else:
            return x_r, maxi_r + bit
 
 
X, ans = sol(a, 0, n - 1, b)
 
print(ans)