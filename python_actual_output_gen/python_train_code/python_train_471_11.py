a = [int(input()) for _ in range(5)]
b = [(10-(i%10)) for i in a]
c = max(b)
print(sum([((j + 9)//10) * 10 for j in a]) - c)