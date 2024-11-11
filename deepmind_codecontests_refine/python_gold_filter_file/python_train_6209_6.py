a, b = input().split()
answer = a[0]
for i in range(1, len(a)):
    if (a[i]<b[0]):
        answer+=a[i]
    else:
        break
print(answer+b[0])