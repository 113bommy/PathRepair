n,k,l,c,d,p,nl,np=[int(x) for x in input().split()]
arr=[]
arr.append(int((k*l)//nl))
arr.append(c*d)
arr.append(int(p//np))
ans=min(arr)
print(int(ans//n))