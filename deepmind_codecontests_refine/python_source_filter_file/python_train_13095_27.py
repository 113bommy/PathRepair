N=int(input())
text=input()
x=0
for i in range(N-1):
  if text[i]!=text[i+1]:
    x+=1
print(x)
