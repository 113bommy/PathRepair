S = int(input())
a = S//3600
b = S%3600//60
c = S%60
print(f"{a}:{b}:{c}")
