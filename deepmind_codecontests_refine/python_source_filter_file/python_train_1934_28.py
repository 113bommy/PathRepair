n = int(input())
b = n//2
print(b)
print("2"*b if n % 2 == 0 else"2 "*(b-1)+"3")