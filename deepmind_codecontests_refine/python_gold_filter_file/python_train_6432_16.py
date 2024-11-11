n = int(input())
x = list(map(int,input().split()))
ave = round(sum(x)/n)
print(sum([(i-ave)**2 for i in x]))