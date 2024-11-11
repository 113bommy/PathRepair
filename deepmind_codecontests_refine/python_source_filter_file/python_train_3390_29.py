n, m = [int(i) for i in input().split()]

for i in range(n):
    x = input()
    if 'C' in x or 'M' in x or 'Y' in x:
        print('#Color')
        break
else:
    print('#Black&Whites')
