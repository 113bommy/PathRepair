def check(n, a):
    a.insert(0, 0)
    a.append(90)
    for i in range(1, len(a)):
        if (a[i] - a[i-1]) > 15:
            return a[i-1]+15 
    return 90

n = int(input())
a = list(map(int, input().strip().split()))
print(check(n, a))