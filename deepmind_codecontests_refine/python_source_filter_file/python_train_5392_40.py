n = int(input())
s = input()
 
print('yes' if s[:n//2] == s[n//2:] else 'no')