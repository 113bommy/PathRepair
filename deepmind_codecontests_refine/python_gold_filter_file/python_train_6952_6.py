a=tuple(input())
len_a=len(a)
b=tuple(input())
len_b=len(b)
c=tuple(input())
len_c=len(c)
flag_ab=[True]*20000
for i in range(len_a):
  for j in range(len_b):
    if a[i]!=b[j] and a[i]!='?' and b[j]!='?':
      flag_ab[i-j+10000]=False
flag_ac=[True]*20000
for i in range(len_a):
  for j in range(len_c):
    if a[i]!=c[j] and a[i]!='?' and c[j]!='?':
      flag_ac[i-j+10000]=False
flag_bc=[True]*20000
for i in range(len_b):
  for j in range(len_c):
    if b[i]!=c[j] and b[i]!='?' and c[j]!='?':
      flag_bc[i-j+10000]=False
ans=len_a+len_b+len_c
left_a=0
for left_b in range(-(len_b+len_c),len_b+len_c+1):
  for left_c in range(-(len_b+len_c),len_b+len_c+1):
    if flag_ab[left_b-left_a+10000] and flag_ac[left_c-left_a+10000] and flag_bc[left_c-left_b+10000]:
      right_a=left_a+len_a
      right_b=left_b+len_b
      right_c=left_c+len_c
      left=min(left_a,left_b,left_c)
      right=max(right_a,right_b,right_c)
      ans=min(ans,right-left)
print(ans)