n, a, b, c, d = map(int, input().split())
s = input()
a-=1
b-=1

index1 = s[a:c].find("##")
index2 = s[b:d].find("##")

ans = "No"

if index1 == -1 and index2 == -1:
  if c < d :
    ans = "Yes"
  elif s[b:d].find("...") != -1 :
    ans = "Yes"
  
print(ans)