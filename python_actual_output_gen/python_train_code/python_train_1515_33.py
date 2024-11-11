def sum(x, y):
    sum = 2 * x + 2 * y - 4
    return sum
    
    
    
w, h, k = list(map(int, input().split()))
summ = 0
for i in range(k):
    summ += sum(w - 2 * i, h - 2 * i)
print(summ)
