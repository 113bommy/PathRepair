n = int(input())
percentage = [int(a) for a in input().split()]
juice = 0

for p in percentage:
    if p < 100:
        p = float(f'0.{p}')
    else:
        p = 1
    juice += p

ans = juice/n * 100
print(f'{ans:.6f}')