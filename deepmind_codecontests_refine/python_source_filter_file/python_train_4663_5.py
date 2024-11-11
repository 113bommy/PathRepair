def divisors(n):
  ret=[]
  for i in range(2,int(n**0.5)+1):
    if n%i==0:
      ret.append(i)
      if n//i!=i:
        ret.append(n//i)
  return ret

n=int(input())
divs1=divisors(n)
divs2=divisors(n-1)
cnt=len(divs2)
for val in divs1:
  if val==1:
    continue
  tmp=n
  while tmp%val==0:
    tmp=tmp//val
  if tmp%val==1:
    cnt+=1
print(cnt)