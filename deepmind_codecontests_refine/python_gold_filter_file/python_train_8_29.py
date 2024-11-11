n = int(input())
s = list(input())
if '8' not in s:
     print(0)
     exit()
print(min(s.count('8') , n // 11))
