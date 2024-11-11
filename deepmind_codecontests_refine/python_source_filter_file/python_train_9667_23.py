h,w=map(int,input().split())
num=0
s=[str(input()) for i in range(h):]
for i in range(h):
  num+=s[i].count("#")
if num>h+w-1:
  print("Impossible")
  exit()
print("Possible")