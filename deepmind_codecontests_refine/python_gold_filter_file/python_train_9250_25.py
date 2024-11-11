a,b,c,d=[int(input()) for i in range(4)]
print(c*min(a,b)+d*max(a-b,0))