h,w = map(int,input().split())
t = "."*(w+2)
b = [t]
for i in range(h):
  s = str(input())
  s = "."+ s + "."
  b.append(s)
b.append(t)
for i in range(1,h+1):
  for j in range(1,w+1):
    if s[i][j] == "#":
      if all([s[i-1][j]==".",s[i+1][j]==".",s[i][j-1]==".",s[i][j+1]=="."]):
        print("No")
        exit()
print("Yes")

  