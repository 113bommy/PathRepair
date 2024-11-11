n = int(input())
a = [-1] + sorted(map(int, input().split()))

for i in range(n):
    if a[n-i] != a[n-i-1] and (i+1)%2 == 1:
        print('Conan')
        break
else:
    print('Agasa')
