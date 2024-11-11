k, l, n, m, d = int(input()), 0, 0, 0, 0
l = int(input())
n = int(input())
m = int(input())
d = int(input())
ile_zyje = d
for x in range(d):
    if x % k == 0 or x % l == 0 or x % n == 0 or x % m == 0:
        ile_zyje -= 1 
print(d - ile_zyje)