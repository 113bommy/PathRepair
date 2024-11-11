a = ""
for _ in range(3):
	a += input()
x = a.count("X")
o = a.count("0")
# print(a)	
ans = []
win = [(0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6), (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)]
for i,j,k in win:
	if a[i] == a[j] and a[j] == a[k]:
		ans.append(a[i])
# print(ans)
if x<o or ('X' in ans and '0' in ans) or ('0' in ans and x>o) or ('X' in ans and x==o):
	print("illegal")	
elif 'X' in ans:
	print("the first player won")	
elif '0' in ans:
    print("the second player won")
elif x==5:
	print("draw")  
elif x==o:
	print("first")
else:
	print("second")		  

