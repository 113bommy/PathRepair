"""n = int(input())
arr = []
decide = 1
for i in range(n):
    temp = int(input())
    if temp%2==0:
        arr.append(temp//2)
    else:
        if decide%2==0:
            arr.append((temp+1)//2)
        else:
            arr.append((temp-1)//2)
        decide += 1
for i in arr:
    print(i)"""