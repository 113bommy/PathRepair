n = int(input())
a = list(map(int, input().split()))

a=sorted(a)
if a[n-1] == a[0] == 1:
    a[n-1] += 1
    print(" ".join(str(k) for k in a))
    quit()
print("1 "+" ".join(str(a[k]) for k in range(n-1)))