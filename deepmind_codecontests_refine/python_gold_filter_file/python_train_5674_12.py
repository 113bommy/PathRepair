from collections import Counter

a , b = map(int , input().split())
r = lambda : list(map(int, input().split()))
arr = [r() for _ in range(b)]

city = [0] * b
for x,i in enumerate(arr):
    city[x] = i.index(max(i)) + 1

brr = [city.count(i) for i in range(1 , a+1)]
print(brr.index(max(brr)) + 1)