n = int(input())
a = list(map(int,input().split()))
sum = 0
sub = 0
for i in a:
    if i < 0:
        sub += i
    else:
        sum += i
result = sum + sub
print(result)