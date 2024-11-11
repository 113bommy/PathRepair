n=int(input(""))
x=int(input(""))
nums=[0,1,2,2,1]
if nums[n%5]==x:    print(0)
elif nums[(n-2)%5]==x:  print(1)
else: print(2)