n = int(input())
a = list(map(int, input().split()))

minodd = 100001
summation = sum(a)

for elem in a:
    if elem % 2 != 0:
         minodd = min(minodd, elem)
if summation % 2 == 0:
    print(summation)
else:
    print(summation - minodd)
