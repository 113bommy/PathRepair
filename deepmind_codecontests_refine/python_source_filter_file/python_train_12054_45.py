N = int(input())

total = sum([i for i in range(1,N+1) if i%3!=0 and i%5!=0]
print(total)