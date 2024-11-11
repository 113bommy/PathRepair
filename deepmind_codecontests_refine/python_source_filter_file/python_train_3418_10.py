s1,s2,s3 = map(int, input().split())
s4,s5,s6 = map(int, input().split())
s7,s8,s9 = map(int, input().split())

if s1-s4=s2-s5=s3-s6 and s4-s7=s5-s8=s6-s9:
  print("Yes")
else:
  print("No")