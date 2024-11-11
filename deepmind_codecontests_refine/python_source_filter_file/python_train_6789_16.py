n=int(input())
for i in range(n):
    a,b=input().split()
    a=int(a)
    print(a*(len(b)-1)+int(int(b)/int("9"*len(b))))