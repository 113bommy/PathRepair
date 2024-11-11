b,s=-1e9,1e9
for _ in range(int(input())):
 r=int(input())
 b,s=max(b,r-s),min(s,r)
print(b)
