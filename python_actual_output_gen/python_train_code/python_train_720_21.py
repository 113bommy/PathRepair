input()
A = list(map(int,input(),split()))
count=0
while all(a%2==0for a in A):
  A = [a/2 for a in A]
  count +=1
print(count)

