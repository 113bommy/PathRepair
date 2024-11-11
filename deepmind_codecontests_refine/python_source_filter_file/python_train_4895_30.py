b,s=-1e7,1e7
for _ in range(int(input())):
 r=int(input())
 b,s=max(b,r-s),min(s,r)
print(b)
