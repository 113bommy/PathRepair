a = int(input())
s = input()
print(s[:a] + '...' * (len(s) >= a))
