inputs=[int(x) for x in input().split()]
m=inputs[0] # number of sides
n=inputs[1] # number of tosses
s=0
for i in range(m):
    s+=(i+1)*((i+1)/m)**n-((i)/m)**n
print(s)