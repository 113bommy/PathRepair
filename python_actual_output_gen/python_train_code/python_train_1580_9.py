s = input()
a = s.count('VK')
s = s.replace('VK', '')
a += 1 if "VV" in s or "KK" in s else 0
print(a)
