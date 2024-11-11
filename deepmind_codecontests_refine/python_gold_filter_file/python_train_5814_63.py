a=input()
b=input()
print(["NO","YES"][b==a[::-1] and a==b[::-1]])
