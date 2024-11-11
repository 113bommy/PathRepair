def f(base,m,c):
	for i in range(16):
		for j in range(32):
			if not m:
				break
			base[2 * i][j * 2] = c
			m -= 1
		else:
			continue
		break
	return base

w,b=map(int,input().split())
print(64,64)
print("\n".join(map("".join,f([["#"]*64 for _ in range(32)],w-1,".")+[["."]*64]+f([["."]*64 for _ in range(31)],b-1,"#"))))