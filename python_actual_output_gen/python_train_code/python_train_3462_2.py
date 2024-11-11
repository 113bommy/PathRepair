import sys

n=int(input())
x=8*n+1
for i in range(50):
    if(i*i==x):
        print("YES")
        sys.exit()
print("NO")