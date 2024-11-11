n = int(input())
arr=['a','a','b','c']
res = ''
for i in range(n):
    res+=arr[i%4]
print(res)
