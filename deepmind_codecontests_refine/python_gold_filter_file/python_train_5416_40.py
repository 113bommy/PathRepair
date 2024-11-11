S = int(input())
H = S//3600
M = S%3600//60
S = S%60
print(f"{H}:{M}:{S}")
