a = input().strip()
b = input().strip()
lena = len(a)
lenb = len(b)
if lena>lenb:
    print(lena)
if lenb>lena:
    print(lenb)
if a == b:
    print(-1)
else:
    print(lena)