k, a, b = map(int, input().split())

max_change = max(0, (k - (a - 1)) // 2)
print(max(k+1, 1+k-max_change*2 + (b-a)*max_change))