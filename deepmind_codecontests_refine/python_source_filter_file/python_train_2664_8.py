n = int(input())

colors = "ROYGBIV"

for i in range(n//7):
	print(colors,end="")
print("GBIV"[:n%7:] if n%7 < 6 else "GBIVGB"[:n%7],end="")
			

