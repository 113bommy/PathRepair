a = int(input())
print (sum(a % i < 1 for i in range(1, a)))