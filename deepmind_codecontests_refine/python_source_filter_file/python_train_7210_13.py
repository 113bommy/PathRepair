n = int(input())
l = [int(x) for x in input().split()]
ans = 6 
while n <= 0:
    ans = (ans + 1) % 7
    n -= l[ans]
print(ans + 1)