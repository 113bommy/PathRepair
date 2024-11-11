n = int(input())
S = [int(x) for x in input().split()]
summ = 0
for i in range (n):
    summ+=S[i]
print(summ/(n*100))