l=int(input())
s=input()
frq={8:0,0:0}
for c in s:
      if c!='8':
            frq[0]=frq[0]+1
      else:
            frq[8]=frq[8]+1
            
l,r=0,9
while r>l+1:
      m=(l+r)//2
      if frq[8]-m>=0 and (frq[0]+frq[8]-m)//10>=m:
            l=m
      else:
            r=m
print(l)

