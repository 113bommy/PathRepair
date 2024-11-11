n = int(input())
arr=['a','a','b','b']
res = ''
for i in range(n):
    res+=arr[i%4]
print(res)
