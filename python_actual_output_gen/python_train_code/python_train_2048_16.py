a = int(input())
li = sorted(map(int, input().split()))
for i in range(a):
    if li[i]%2 == 1:
        pass
    else:
        li[i] -= 1
for i in li:
    print(i, end= ' ')