
s = str(input())
prev = 0
prevv = 0

for i, c in enumerate(list(s.strip())):
    cur = ord(c) - ord('A')
    if i >= 2 and cur != int(prev + prevv) % 26:
        print("NO")
        exit(0)
    
    prevv = prev
    prev = cur

print("YES")
    