a=input()
b=input()

aCount = 0# if a[0]=='1' else 0

for i in range(0,len(b)):
  aCount += (1 if a[i]=='1' else 0)

bCount=0
for i in range(len(b)):
  bCount+= 1 if b[i]=='1' else 0

res=0
#print(ones,bCount)
for i in range(0,len(a)-len(b)):
  #print((ones[i+len(b)-1]-ones[i-1]) %2 , ones[i+len(b)-1],ones[i-1],bCount%2)
  #print(aCount,bCount)
  if( aCount %2 == bCount%2):
    #print(a[i:i+len(b)])
    res+=1
  
  #print("::",a[len(b)+i],a[i],"index:",len(b)+i,i)
  #if coming char ==1 increase count(out of coundary)
  aCount+=(1 if a[len(b)+i]=='1' else 0)
  #print("after1",aCount,bCount)
  #if going  char==1 decrease count
  aCount-= 1 if  a[i]=='1' else 0
  #print(1 if  a[i]=='1' else 0)
  #print("after2",aCount,bCount)
if( aCount %2 == bCount%2):
    #print(a[i:i+len(b)])
    res+=1

print(res)



