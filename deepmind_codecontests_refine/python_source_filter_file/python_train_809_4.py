_, *a = map(int, open(0).read().split());z = 0
for b in a:z ^= b
print("YNeos"[z>0])