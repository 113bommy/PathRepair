n = int(input())

# x = n とおくと
# 2/n = 1/n + 1/y + 1/z
# 1/n = 1/y + 1/z　= (z + y)/yz
# これを変形
# yz = n(z + y) = nz + ny
# (y - n)z = ny
# z = ny/(y - n)
# zは整数だからnyはy-nの倍数
# シンプルにy-n=1となるようにyを取ると y=n+1, z=n*(n+1)

x = n
y = n + 1
z = n * (n + 1)

if n <= 2 or z > 10 ** 9:
    print(-1)
else:
    print(x, y, z)
