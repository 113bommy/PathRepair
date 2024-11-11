#taking input
inp=input().split()
n=int(inp[0])
k=int(inp[1])
inp=input().split()
reg=list(map(int,inp))

s=sum(reg)
x=n*(2*k-1)-2*s
print(max(x,0))
