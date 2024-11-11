input()
c=1
s=d=0
for x in map(int,input().split()):c&=x!=0;d+=x<0;s+=min(abs(x-1),abs(x+1))
print(s+c*d%2*2)