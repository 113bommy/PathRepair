n = (int)(input())
for i in [2]+[(x+2)*(x*x)+1 for x in range(2,n+1)]:
    print(i)