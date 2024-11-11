
n = (input().split())
m = int(n[1])
n = int(n[0])
mat = [0]*n
total = compress = 0

for i in range(n):
    temp = (input().split())
    total += int(temp[0])
    compress += int(temp[1])
    mat[i] = int(temp[0]) - int(temp[1])

mat.sort(reverse=True)
for i in range(n-1):
    mat[i+1] += mat[i]

# print(m, compress, total, m-total)
# print(mat)
if total == m:
    print(0)

else:
    if m < compress:
        print(-1)
    else:
        diff = total - m
        for i in range(n):
            if diff <= mat[i]:
                print(i+1)
                break
