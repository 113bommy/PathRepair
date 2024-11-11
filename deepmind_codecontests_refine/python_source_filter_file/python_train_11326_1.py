h,w,a,b = map(int,input().split())

for i in range(b):
    print("1"*a + "0"*(w-1))
for j in range(h-b):
    print("0"*a + "1"*(w-1))