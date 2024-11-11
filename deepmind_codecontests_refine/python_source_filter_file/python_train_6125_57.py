a,b,c,d = list(map(int, input().split()))
print("Left" if a+b > c+d else "Right" if a+b > c+d else "Balanced")