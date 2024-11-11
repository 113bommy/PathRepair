n = int(input())
r=[]
count=0
for i in range(n):
     s=input()
     r.append(s)
for i in range(n-1):
     if r[i]!=r[i+1]:
          count+=1
print(count)