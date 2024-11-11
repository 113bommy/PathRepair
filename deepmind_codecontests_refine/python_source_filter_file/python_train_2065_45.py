n = input()
a = list(map(int, input().split()))
cut=0
 
while all(i%2==0 for i in a):
  list=[i/2 for i in a]
  cut+=1
print(cut)

