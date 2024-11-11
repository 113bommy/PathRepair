p='ROYGBIV'
n=int(input())
ap=n//7
rem=n%7
last=["G", "GY", "YGB", "YGBO", "OYGBI" ,"OYGBIV" ]
p=p*ap
print(p+ last[rem-1] if rem>=1 else p)
