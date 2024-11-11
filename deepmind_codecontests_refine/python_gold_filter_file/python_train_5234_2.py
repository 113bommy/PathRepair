s = int(input())
for a in range(s):
    h,i = map(int,input().split( ))
    print((i-h%i)%i)