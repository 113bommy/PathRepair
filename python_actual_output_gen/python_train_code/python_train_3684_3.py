nzint = input().split()
nz=[int(x) for x in nzint]
input_string = input().split()
intlist =[int(x) for x in input_string]
intlist.sort()
i,j = nz[0]-1 , (nz[0]-1)//2
count = 0
while i>=(nz[0]-1)//2 and j>=0:
    if intlist[i]-intlist[j]>=nz[1]:
        count = count + 1
        i=i-1
    j=j-1
    
print (count)