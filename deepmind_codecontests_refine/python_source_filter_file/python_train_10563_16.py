n,m=map(int,input().split())
my_dict={}

for i in range(m):
    a,b=input().split()
    my_dict[a]=b


inp=input().split()

for i in range(n):
    if len(inp[i]) >= len(my_dict[inp[i]]):
        print(inp[i],end=" ")
    else:
        print(my_dict[inp[i]],end=" ")