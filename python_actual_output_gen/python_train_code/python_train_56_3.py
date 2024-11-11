line = [int(x) for x in input().split()]
n = sum(line)
if n % 5 == 0 or n == 0 :
    print(int(n/5))
else:
    print(-1)
