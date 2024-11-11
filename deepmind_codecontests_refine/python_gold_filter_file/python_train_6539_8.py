_, *a = open(0)
print(["second","first"][any(int(b)%2 for b in a)])