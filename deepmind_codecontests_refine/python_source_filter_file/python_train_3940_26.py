n=int(input());k=int(input()),r=1
for _ in[0]*n:r+=min(r,k)
print(r)