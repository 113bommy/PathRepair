h,m = [int(i) for i in input().split(':')]
t = int(input())
h2 = (h*60+m+t)%(24*60)
print("%02d:%02d" %(h2//60,h2%60))