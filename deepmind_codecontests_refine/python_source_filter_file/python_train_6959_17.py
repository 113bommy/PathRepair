n = int(input())
x = round(n**0.5)

while n%x!=0:
    x += 1
y = n//x
print(len(str(max(x,y))))