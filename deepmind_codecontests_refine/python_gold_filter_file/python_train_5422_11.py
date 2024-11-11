x = int(input())
h = x//(60*60)
m = (x//60)%60
s = x%60
print(h,m,s,sep=":")