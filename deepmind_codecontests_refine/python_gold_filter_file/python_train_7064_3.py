A=list(input())
for i in range(len(A)):
  if A[i]=="C":
    if "F" in A[i+1:]:
      print("Yes")
      exit()
print("No")
