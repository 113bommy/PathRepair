a = int(input())
count = 0
mod = 0
for i in range(a):
    b = int(input())
    if b == 0:
        mod = 0
    c = b + mod
    if not c==0:
        count += b//2
        mod = b%2
print(count)