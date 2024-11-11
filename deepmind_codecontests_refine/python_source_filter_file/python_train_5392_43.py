n = int(input())
s = input()

print("YNoes"[s[0:int(n/2)] != s[int(n/2):n]::2])
