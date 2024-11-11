yes,no,z=list(map(int,input().split()))
if z==0 and yes==no:
    print(0)
elif yes > no+z:
    print("+")
elif yes+z <= no :
    print("-")
else:
    print("?")