z={
  'purple':'Power', 
  'green':'Time', 
  'blue':'Space', 
  'orange':'Soul', 
  'red':'Reality', 
  'yellow':'Mind'
}
x=[ 'purple', 'green', 'blue', 'orange', 'red', 'yellow']
y=[]
a=int(input())
for i in range(a):
  b=input()
  y. append(b)
print(len(x)-len(y))
for i in range(6):
  if x[i] not in y:
    
    print(z[x[i]])