import fractions
N = int(input())
A = list(map(int, input().split()))
AB = 1
for i in A:
    AB = AB*i//fractions.gcd(AB,i)
sumB = 0
for i in A:
    sumB += AB//i
print(int(sumB%(10**9+7)))