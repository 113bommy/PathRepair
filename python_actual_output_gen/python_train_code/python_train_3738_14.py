n=int(input())
if(n%2!=0):
    print(0)
elif((n//2)%2!=0):
    print(int(n//2))
else:
    print(int(n//2)-1)
