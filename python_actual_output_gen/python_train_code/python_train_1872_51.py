n = input()
l = list(map(int, input().split()))
print(["No","Yes"][sum(l)-max(l) >= max(l)])