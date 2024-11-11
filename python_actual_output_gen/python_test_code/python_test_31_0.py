m,d = map  (  int ,( input().split() )  )
list=[0,31,28,31,30,31,30,31,30,31,30,31,30]
print((list[m] + d + 5 )//7 )
