n = int(input())
a = list(map(int,input().split()))
b = sorted(a)
if a == b:
    print("YES")
else:
    changes = 0
    flag = True
    for i in range(n):
        if a[i]!=b[i]:
            changes += 1
            if changes > 2:
                flag = False
                break
    if changes==2 and flag:
        print("YES")
    else:
        print("NO")