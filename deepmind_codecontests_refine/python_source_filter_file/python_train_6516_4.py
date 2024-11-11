x=int(input())
y=x%4
z=x//4
print("aabb"*z,end="")
if y:
  print("a")
elif y==2:
  print("aa")
elif y==3:
  print("aab")