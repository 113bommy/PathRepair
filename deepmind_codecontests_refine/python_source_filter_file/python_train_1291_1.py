r, h = map(int, input().split())
if (h%r)/r >= 3**0.5: print(2*(h//r)+3)
elif 0.5 <= (h%r)/r : print(2*(h//r)+2)
else: print(2*(h//r)+1)