n=int(input())
m=n//7
r=n%7
print(str(m+max(0,r-5))+' '+str(m+min(r,2)))