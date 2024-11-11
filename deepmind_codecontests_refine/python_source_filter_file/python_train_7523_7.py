def subarraySum(nums,k):
    s = 0
    out = 0
    d = {}
    ln = len(nums)
    i = 0
    while i<ln:
        s += nums[i]
        if s == k:
            out += 1
            s += 10**10
            s -= nums[i]
            i-=1
        if s-k in d:
            out += d[s-k]
            s += 10**10
            s -= nums[i]
            i-=1
        d[s] = d.get(s,0)+1
        i+=1
    return out

n = int(input())
a = list(map(int,input().split()))
out = subarraySum(a,0)
print(out)
