n = int(input())
coshelki = [int(i) for i in input().split()]
x, f = (int(i) for i in input().split())

sum = 0
for i in coshelki:
    perevody = i // (x + f)
    if i - perevody * x > x:
        perevody += 1
    sum += perevody

print(f * sum)