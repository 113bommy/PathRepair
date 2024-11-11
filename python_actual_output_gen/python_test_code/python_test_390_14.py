N = int(input())
print(sum([i for i in range(1,N) if not(i%5==0 or i%3==0)]))