n = int(input())
a = [int(x) for x in input().split()]
if n == 1:
    print(0)
else:
    if a[0] > a[1]:
        max = a[0]
        min = a[1]
    else:
        max = a[1]
        min = a[0]
    if n % 2 == 0:
        for i in range(2,n,2):
            if a[i] < a[i+1]:
                if a[i] < min:
                    min = a[i]
                if a[i+1] > max:
                    max = a[i]
            else:
                if a[i] > max:
                    max = a[i]
                if a[i+1] < min:
                    min = a[i+1]
    else:
        for i in range(2,n-1,2):
            if a[i] < a[i+1]:
                if a[i] < min:
                    min = a[i]
                if a[i+1] > max:
                    max = a[i]
            else:
                if a[i] > max:
                    max = a[i]
                if a[i+1] < min:
                    min = a[i+1]
        if a[-1] > max:
            max = a[-1]
        elif a[-1] < min:
            min = a[-1]
    print(max - min + 1 - n)


