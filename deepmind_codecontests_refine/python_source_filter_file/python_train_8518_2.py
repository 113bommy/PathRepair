s=input()
l=list("AKIHABARA".split("A"))[1:-1]

for ii in range(2**4):
  p="A" if ii%2 else ""
  i=ii
   for j in range(3):
    p+=l[j]
    i//=2
    p+="A" if i%2 else ""
  if s==p:print("YES");exit()
print("NO")