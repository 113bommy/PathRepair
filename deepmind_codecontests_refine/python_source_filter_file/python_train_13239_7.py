n = input()
n = int(n,2)
count = 0
for i in range(51):
    if 4**i<=n:
        count+=1
print(count)
