a = ['q', 'r', 'b', 'n', 'p', 'k']
s = [9, 5, 3, 3, 1, 0]
white = 0
black = 0

for _ in range(8):
    z = input()
    for i in range(6):
        if a[i] in z:
            black += (s[i])*z.count(a[i])
        elif a[i].upper() in z:
            white += (s[i])*z.count(a[i].upper())
            
            
if white > black:
    print("White")
elif white == black:
    print("Draw")
else:
    print("Black")