#problem94
n = int(input())
s = input()
for i in range(len(s)-1):
    if s[i] == s[i + 1] and s[i] != '?':
        print("No")
        break
if s[0] == '?' or s[-1] == '?' or ('??' in s) or ('M?M' in s) or ('C?C' in s) or ('Y?Y' in s):
    print("Yes")
else:
    print("No")