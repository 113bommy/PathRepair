n=int(input())
vector1=[int(x) for x in input().split()]
vector2=[int(x) for x in input().split()]
for i in range(1,4):
print("{0:.8f}".format(sum([abs(a-b)**p for a,b in zip(vector1,vector2)])**(1/p)))
print("{0:.8f}".format(max([abs(a-b) for a,b in zip(vector1,vector2)])))