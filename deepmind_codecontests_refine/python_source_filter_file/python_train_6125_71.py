a,b,c,d = map(str,input().split())
print("Left" if a+b > c+d else "Balanced" if (a+b) == (c+d) else "Right")
