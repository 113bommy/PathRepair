n = int(input())
mx = 1
for i in range(2,int(n**(1/2))+1):
  if n%i == 0:
    mx = i
print(len(str(n//mx)))
    
    