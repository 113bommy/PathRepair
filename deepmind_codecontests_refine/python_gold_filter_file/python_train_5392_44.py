n = int(input())
s = input()

print("YNeos"[s[0:int(n/2)] != s[int(n/2):n]::2])
