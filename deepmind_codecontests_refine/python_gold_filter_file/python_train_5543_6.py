n, k = map(int, input().split())
m = list(map(int, input().split()))
c = list(map(int, input().split()))
m.sort()
count = 0
result = 0
for i in range(n):
    count += 1
    reqd = count//(c[m[~i] - 1])
    if count%(c[m[~i] - 1])!=0:
        reqd +=1
    result = max(result, reqd)

arrays = [[] for _ in range(result)]
count = [0] * k
for i in range(n):
    count[m[i] - 1] += 1
temp = 0

for i in range(k -1, -1, -1):
    
    for j in range(count[i]):
        
        arrays[temp%result].append(i + 1)
        temp += 1
    
print(result)
for arr in arrays:
    print(len(arr), *arr)