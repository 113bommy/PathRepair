times=int(input())
for i in range(times):
    a=int(input())
    b=int(input())
    if len(str(a))<=80 and len(str(b))<=80 and len(str(a+b))<=80:
        print(a+b)
    else: print("overflow")