a, b = [int(i) for i in input().split(" ")]
print("IMPOSSIBLE" if (a+b)%2 else (a+b)//2)
