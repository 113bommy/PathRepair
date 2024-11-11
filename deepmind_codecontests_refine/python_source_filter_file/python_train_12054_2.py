n=int(input())
print(sum([i for i in range(n) if not (i%3==0 or i%5==0)]))
