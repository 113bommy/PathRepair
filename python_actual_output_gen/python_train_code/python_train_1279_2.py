s = input()
p = 1

for c in s:
    q = ord(c) - ord('a')
    if q == p:
        p += 1
    elif q > p: 
        print("NO")
        exit()

print("YES")
