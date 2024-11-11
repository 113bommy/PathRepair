dad,mom,son,Masha = [int(i) for i in input().split()]
if Masha > 2*son or son > 2*Masha:
    print(-1)
elif Masha >= dad*2 or Masha >= mom*2:
    print(-1)
else:
    print(2*dad,2*mom,min(2*Masha,2*son))
