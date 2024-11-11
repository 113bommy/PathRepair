h,w=map(int,input().split())
lis = []
for _ in range(h):
 lis.append(input())
for i in range(h):
 for j in range(w):
  if lis[i][j] = "#":
    if (i == 0 or lis[i-1][j] == ".") and (j==0 or lis[i][j-1] == ".")  and (i == h-1 or lis[i+1][j] == ".") and (j == w-1 or lis[i][j+1] == "."):
      print("No")
      quit()
print("Yes")