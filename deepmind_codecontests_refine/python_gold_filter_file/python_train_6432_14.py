n = int(input())
x = list(map(int, input().split()))
av = round(sum(x)/n)
print(sum([(i-av)**2 for i in x]))