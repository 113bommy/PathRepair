A,B,X = map(int,input().split())
s = "Yes"
if A > X or A+B < X:
  s = "No"
print(s)