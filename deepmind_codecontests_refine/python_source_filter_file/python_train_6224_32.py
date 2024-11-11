string=input()
length=len(string)
mod=[1]+[0]*2018
s=0
for i in range(length):
  s=(s+int(string[-1-i])*pow(10,i))%2019
  mod[s]+=1
print(sum([i*(i-1)//2 for i in mod]))
