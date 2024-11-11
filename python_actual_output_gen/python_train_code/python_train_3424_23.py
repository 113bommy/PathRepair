def prefixSum(lst):
    a =[0] + lst
    s = [0]*(len(a))
    s[0],s[1] = 0,a[1]
    for i in range(1,len(a)):
        s[i] = s[i-1] + a[i]
    return s
n, k = list(map(int,input().split()))
lst = list(map(int,input().split()))
lst = prefixSum(lst)
reham = 0
mini = 10**6
for i in range(n-k):
    if lst[i+k]-lst[i] < mini:
        reham = i
        mini = lst[i+k]-lst[i]
print(reham+1)
