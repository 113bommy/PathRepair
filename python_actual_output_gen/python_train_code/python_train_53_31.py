arr = input().split('+')
n = len(arr)
for i in range(n):
    arr[i] = int(arr[i])
# print(arr)

arr_ = sorted(arr)
stree = str()
for i in range(n):
    stree += str((arr_[i]))+'+'
    
print(stree[:n+n])