k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())
counter = 0
tab = [i for i in range(1 , d + 1)]
for i in range(k - 1 , d , k):
    tab[i] = 1
for i in range(l - 1 , d , l):
    tab[i] = 1
for i in range(m - 1 , d , m):
    tab[i] = 1
for i in range(n - 1 , d , n):
    tab[1] = 1
print(tab.count(1))