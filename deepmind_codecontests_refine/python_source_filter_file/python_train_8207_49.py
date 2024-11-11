x = int(input())
ret = x // 11 * 2 
x = x % 11
ret += 2 if x > 5 else 1 if x > 0 else 0
print(ret)