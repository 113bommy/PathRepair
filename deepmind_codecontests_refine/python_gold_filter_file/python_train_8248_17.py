a = int(input())
for _ in range(a):
    x= int(input())
    li = list(map(int, input().split()))
    b = max(li)
    p = -1
    for i in range(1,1025):
        for j in li:
            if j^i not in li:
                break
        else: p =i; break
    print(p)
