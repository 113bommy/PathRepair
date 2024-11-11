n = int(input())
x = 0
for i in range(n):
    pi, qi = list(map(int, input().split()))
    if((qi-pi)>2):
        x = x + 1

print(x)