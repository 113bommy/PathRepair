n=int(input())
x=input()
if len(set(x))==1:print("NO")
else:
    print("YES")
    for i in range(len(x)-1):
        if x[i]!=x[i+1]:print(x[i]+x[i+1]);
