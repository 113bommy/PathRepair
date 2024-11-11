f=[1,1]
for _ in[0]*43:f+=[f(-2)+f(-1)]
print(f[int(input())])
