z = input()
a = input()

a=list(a)

for i in range(2,(int(len(a)/2))+1):
  if len(a)%i==0:
    for j in range(int(i/2)):
      a[j],a[i-j-1] = a[i-j-1],a[j]
      #print(''.join(a))


a = reversed(a)

print(''.join(a))