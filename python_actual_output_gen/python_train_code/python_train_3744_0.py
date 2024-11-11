n = int(input())
s = input()

freq = {}
freq['L']=0
freq['R']=0
freq['U']=0
freq['D']=0
for c in s:
  freq[c]+=1
  
x = min(freq['L'],freq['R'])
y = min(freq['U'],freq['D'])

print(x+y)