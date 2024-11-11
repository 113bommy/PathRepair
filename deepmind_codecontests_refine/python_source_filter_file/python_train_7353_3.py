n = int(input())
a = [-1] + sorted(map(int, input().split()))

for i in range(n):
    if a[n-i-1] != a[n-i-2] and (i+1)%2 == 0:
        print('Conan')
        break
else:
    print('Agasa')
