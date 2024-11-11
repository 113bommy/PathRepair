k=int(input())
ans=[]
for i in range(1,10): #1桁の数
  ans.append(str(i))
  
for i in range(1,10): #2桁の数
  ans.append(str(i)+'9')
  
for i in range(1,10): #3桁の数
  ans.append(str(i)+'99')
  
for i in range(10): #4桁の数
  ans.append('1'+str(i)+'99')
for i in range(2,10): #4桁の数
  ans.append(str(i)+'999')
  
for i in range(1,3): #5桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'999')
for i in range(3,10): #5桁の数
  ans.append(str(i)+'9999')
  
for i in range(1,4): #6桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'9999')
for i in range(4,10): #6桁の数
  ans.append(str(i)+'99999')
  
for i in range(1,5): #7桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'99999')
for i in range(5,10): #7桁の数
  ans.append(str(i)+'999999')

for i in range(1,6): #8桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'999999')
for i in range(6,10): #8桁の数
  ans.append(str(i)+'9999999')
  
for i in range(1,7): #9桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'9999999')
for i in range(7,10): #9桁の数
  ans.append(str(i)+'99999999')

for i in range(1,8): #10桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'99999999')
for i in range(8,10): #10桁の数
  ans.append(str(i)+'999999999')

for i in range(1,9): #11桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'999999999')
for i in range(9,10): #11桁の数
  ans.append(str(i)+'9999999999')
  
for i in range(1,10): #12桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'9999999999')
for i in range(10,10): #12桁の数
  ans.append(str(i)+'99999999999')

for i in range(1,10): #13桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'99999999999')
for i in range(10,10): #13桁の数
  ans.append(str(i)+'999999999999')
  
for i in range(1,10): #14桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'999999999999')
for i in range(10,10): #14桁の数
  ans.append(str(i)+'9999999999999')

for i in range(10): #15桁の数
  ans.append('10'+str(i)+'999999999999')
for i in range(1,10): #15桁の数
  ans.append('1'+str(i)+'9999999999999')
for i in range(2,10): #15桁の数
  for j in range(10):
    ans.append(str(i)+str(j)+'99999999999999')
  
for val in ans[300:k]:
  print(val)
