d=[0]*100
for i in range(int(input())):
  s=str(i+1)
  d[int(s[0])*10+int(s[-1])]+=1
print(sum(d[i]*d[i%10*10+i//10]for i in range(100)))