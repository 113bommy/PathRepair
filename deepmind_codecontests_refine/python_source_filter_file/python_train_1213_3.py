x,y,z=map(int, input('').split())
ar=list(map(int, input('').split()))
ar1=sorted(ar[1:])
ar1=ar1[::-1]
sumtot=sum(ar)
ct=0

while(y*ar[0]<z*sumtot):
    sumtot=sumtot-ar1.pop()

print(len(ar)-len(ar1)-1)
    