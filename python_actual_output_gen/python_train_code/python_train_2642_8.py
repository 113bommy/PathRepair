a,b = map(int,input().split())
print("YES")
for i in range(a,b+1,2):
    print(a+i-1,a+i)