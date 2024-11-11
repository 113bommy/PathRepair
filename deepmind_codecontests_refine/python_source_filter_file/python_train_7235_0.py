n = int(input())
li = list(map(int, input().split()))
st =False
res = 0
for i in range(n-1):
    if i==0:
        res += li[i]
    res += abs(li[i]-li[i+1])
print(res)