d1, d2, d3 = list(map(int, input().split()))
first = 2*d1+2*d2
second = d1+d2+d3
third = d1+2*d3
fourth = 2*d2+2*d3
print(min(first, second, third, fourth))