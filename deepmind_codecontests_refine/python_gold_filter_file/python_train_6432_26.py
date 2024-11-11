n = int(input())
x = list(map(int, input().split()))
s = round(sum(x)/n)
print(sum([(i-s)**2 for i in x]))