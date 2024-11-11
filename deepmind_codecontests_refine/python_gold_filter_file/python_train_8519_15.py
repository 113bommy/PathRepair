N = int(input())
a = list(map(int, input().split()))
a.sort()
k = a.count(a[0])
if a[-1] - a[0] > 1:
    print('No')
elif a[-1] == a[0]:
    if N == a[0] + 1:
        print('Yes')
    elif N//2 >= a[0]:
        print('Yes')
    else:
        print('No')
elif a[-1] < k + 1:
    print('No')
elif a[-1] > (N-k)//2 + k:
    print('No')
else:
    print('Yes')