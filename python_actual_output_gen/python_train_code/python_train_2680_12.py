a = input()
b = input()
c = input()
print(a[0] , c[-1] , a[-1] , c[0] ,b[0] , b[-1] ,a[1] ,c[2])
if a[0] == c[-1] and a[-1] == c[0] and b[0] == b[-1] and a[1] == c[1]:
	print("YES")
else:
	print("NO")
