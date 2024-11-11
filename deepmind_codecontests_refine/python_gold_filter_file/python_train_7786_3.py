S = int(input())
m = 10 ** 9
x = (m-S%m)%m
y = (S+x)//m
print("0 0 {} 1 {} {}".format(m, x, y))