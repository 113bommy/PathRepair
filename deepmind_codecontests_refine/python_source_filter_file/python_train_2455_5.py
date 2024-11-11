a = input()
arr = []
b = input().split(' ')
for j in range(len(b)):
    arr.append(int(b[j]))
c = sorted(arr)
print(c[len(c)//2 + 1])