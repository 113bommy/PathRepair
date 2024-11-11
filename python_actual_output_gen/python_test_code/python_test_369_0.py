w,h,x,y,r = map(input().split())
print(['No','Yes'][r<=x<=w-r and r<=y<=h-r])
