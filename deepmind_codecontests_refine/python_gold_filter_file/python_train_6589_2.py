n = int(input())
s = input()
print('NYOE S'[sum(int(i) for i in s[:n // 2]) == sum(int(i) for i in s[n // 2:]) and not set(s) - {'4', '7'} :: 2])