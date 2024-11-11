n = int(input())
a = list(map(int, input().split()))
av = round(sum(a)/n)
x=0
for i in a:
    x = x + (av)**2 
print(x)