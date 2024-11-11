n = int(input())
l = []
while n:
    N -= 1
    l.append(chr(97+(n % 26)))
    n //= 26

print("".join(l[::-1]))
