x,y,z=map(int,(input().split()))
ans=1
x-=(y+2*z)
print(ans+x//(y+z))