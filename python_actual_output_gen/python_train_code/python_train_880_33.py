n = int(input())
l = list(input())
a = list(input().split())
for i in range(n):
    if  int(l[i]) < int(a[int(l[i]) - 1]):
        for j in range(i, n):
            if int(l[j]) < int(a[int(l[j]) - 1]):
                l[j] = a[int(l[j]) - 1]
            else:
                break
        break
print(''.join(l))