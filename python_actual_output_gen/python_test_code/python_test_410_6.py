l,r=map(int,(input().split()))
for i in range(64,-1,-1):
    if(((1<<i)&l)!=((1<<i)&r)): break
print((1<<(i+1))-1)