n=int(input())
s=input()
l=[input().split("->") for i in range(n)]
if n%2==0:
    print("home")
else:
    print("contest")
    