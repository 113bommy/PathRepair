l = int(input())
h = l//3600
m = l%3600//60
s = l%60
print(f"{h}:{m}:{s}")
