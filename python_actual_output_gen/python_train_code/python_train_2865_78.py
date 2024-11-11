n = int(input())
for i in range(n):
    hh, mm = [int(n) for n in input().split()]
    print(1440 - hh*60+mm)
