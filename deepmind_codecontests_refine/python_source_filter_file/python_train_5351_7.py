r,c=map(int,input().split());a=[input() for _ in[0]*r]
s=lambda x:sum(i.count('S') for i in x)
print(r*c-s(a)*s(zip(*a)))