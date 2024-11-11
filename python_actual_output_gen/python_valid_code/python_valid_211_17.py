n,m=map(int,input().split())
a=list(map(int,input().split()))
d=[]
a.sort()
d.append(float(a[0]-0))
a.append(float(a[-1]-m))
for i in range(len(a)):
    
    if i !=len(a)-1:
     d.append((a[i+1]-a[i])/2)
print(str(max(d))+'000000000')
      