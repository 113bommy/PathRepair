n=int(input())
x = ""
while n!=0:
    x = str(n%2) + x
    n = -(n//2)
if x = "":
    print(0)
else:
    print(x)