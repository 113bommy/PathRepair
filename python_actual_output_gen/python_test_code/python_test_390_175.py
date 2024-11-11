n=int(input())
f=0
for i in range(n):
    if (i%3 != 0) and (i%5 != 0): f+=i
print(f)