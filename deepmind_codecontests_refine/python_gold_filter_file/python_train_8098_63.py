N = int(input())
n = 0
for i in range(1,N+1):
    if len(str(i))%2==1:
        n += 1
print(n)