n=int(input())+1
a=0
for i in range(1,n):
 for j in range(i,n,i):a+=j
print(a)