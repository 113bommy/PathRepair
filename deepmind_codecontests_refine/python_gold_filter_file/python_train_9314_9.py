#n = int(input())
n, k, m = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
l = 0
while a != []:
    i = 1
    while i != len(a):
        if (a[0][0] - k) * (a[i][1] - m) == (a[i][0] - k) * (a[0][1] - m):
            a.pop(i)
        else:
            i += 1
    a.pop(0)
    l += 1
print(l)