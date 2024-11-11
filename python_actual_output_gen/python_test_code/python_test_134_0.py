n = int(input())
a = list(map(int,input().split()))

for i in range(n):
    a[i] += i
a = list(set(a))
if n > len(a):
    print(':(')
else:
    for i in range(len(a)):
        a[i] -= i
    print (" ".join(map(str, a)))
