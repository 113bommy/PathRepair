n,m,r = [int(i) for i in input().split()]
pok = [int(i) for i in input().split()]
pr = [int(i) for i in input().split()]
pk_m = min(pok)
p_m = max(pr)
c = r+1
c =r //pk_m
r = r%pk_m 
for j in range(c):
    r+=p_m
print(max(c-1,r))