n = int(input())
a = list(map(int,input().split()))
if n == 3:
    if ((a[0] < a[1] < a[2]) or (a[0] > a[1] > a[2])):
        print("YES")
    else:
        print("NO")
elif n > 3:
    l = a.index(max(a))
    if (l == 0 and all(a[item] > a[item+1] for item in range(n-1))) or (l == -1 and all(a[item] < a[item+1] for item in range(n-1))):
        print("YES")
    elif (all(a[item] < a[item+1] for item in range(l-1)) and all(a[item] > a[item+1] for item in range(l+1,n-1))) or (all(a[item] > a[item+1] for item in range(l-1)) and all(a[item] < a[item+1] for item in range(l+1,n-1))):
        print("YES")
    else:
        print("NO")













