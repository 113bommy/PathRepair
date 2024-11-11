n=int(input())
a=[0]* 1000001 
c=[0]* 1000001
for i in input().split():
  i = int(i)
  a[i] += 1
  c[a[i]]+=1
#print('init c[4]:',c[4],'c[2]:',c[2],'c[6]:',c[6],'c[8]:',c[8])
for _ in range (int(input())):
  j =input().split()
  if j[0] =='+':
    a[int(j[1])]+=1
    c[ a[int(j[1])]]+=1
  elif j[0]=='-':
    c[ a[int(j[1])]]-=1
    a[int(j[1])]-=1
  if (c[4]>1 or c[8]>=1) or (c[2]>1 and c[6]>=1) or (c[4]>=1 and c[2]>=3):
    #print('c[4]:',c[4],'c[2]:',c[2],'c[6]:',c[6],'c[8]:',c[8])
    print('YES')
  else:
   # print('c[4]:',c[4],'c[2]:',c[2],'c[6]:',c[6],'c[8]:',c[8])
    print('NO')
            


