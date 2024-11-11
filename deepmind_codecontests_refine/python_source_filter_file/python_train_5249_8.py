n, b, p = input().split()
n = int(n)
b = int(b)
p = int(p)
arr = input().split()

for a in range(len(arr)):
    if arr[a] == 1 :
        b -= 1
    else :
        p -= 1

if p < 0 :
    b -= abs(p)

result = abs(b)
if b > 0 : result = 0
print(result)