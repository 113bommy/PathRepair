a = input()
print(min([abs(753-int(a[i:i+3])) for i in range(len(a)-2)]))