a = input()
print(min(abs(int(a[i:i+3])-753) for i in range(len(a)-2)))
