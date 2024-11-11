t = int(input())
arr = []
v = t
while v:
    s = input()
    arr.append(s)
    v = v - 1
arr2 = []
c = 0
a=''
b=''
for i in range(t-1):
    a = arr[i]
    b = arr[i+1]
    for j in range(len(a)):
        if a[j]==b[j]:
            c = c + 1
        else:
            arr2.append(c)
            c = 0
            break
print(max(arr2))
