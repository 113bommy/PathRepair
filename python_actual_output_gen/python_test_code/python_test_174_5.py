n, x = map(int,input().split())
a = [int(k) for k in input().split()]
freq = {}
ans = 0
for k in a:
    ans += freq.get(x^k,0)
    freq[k] = freq.get(k,0)+1
print(freq[k])