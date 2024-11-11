a=int(input())
for x in range(a):
    b=input()
    if(len(b)>10):
        print("%s%d%s"%(b[0],len(b),b[-1]))
    else:
        print(b)