N = int(input())
name = ''
while N != 0:
    name = chr(ord('a') + (N-1) % 26)+name
    N = N // 26
print(name)
