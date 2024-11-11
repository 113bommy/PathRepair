t=int(input())
while(t):
 t-=1
 a=input()
 if(a[-2::]=='po'):
  print("FILIPINO")
 elif(a[-4::]=='desu' or a[-4::]=='masu'):
  print("JAPANSESE")
 else:
  print("KOREAN")

