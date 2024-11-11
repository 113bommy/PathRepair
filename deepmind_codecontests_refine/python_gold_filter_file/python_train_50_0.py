n,m=map(int,input().split());
a=[]
for _ in " "*n:a+=map(int,input().split()[1:])
print("YNEOS"[len(set(a))!=m::2]) 