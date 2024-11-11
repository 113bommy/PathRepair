#author: Harshad

n, m  = map(int, input().split())
list_ = list(map(int, input().split()))
freq = [0]*(n+1)
for ele in list_:
    freq[ele] += 1
res = m+1
for i in range(1, n+1):
    res = min(res, freq[i])
print(res)