a,b,c =map(int,input().split())
for num in range(1,b):
	if a*num%b==c :	
		print("YES");sys.exit(0);
print("NO")
