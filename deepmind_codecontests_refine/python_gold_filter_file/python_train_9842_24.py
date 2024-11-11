PI=3.1415926535
d,h,v,e=[int(i)for i in input().split()]
ans = (PI*d*d*h)/(4*v-PI*d*d*e)
print("NO"if ans < 0 else "YES\n"+"{0:.10f}".format(ans))