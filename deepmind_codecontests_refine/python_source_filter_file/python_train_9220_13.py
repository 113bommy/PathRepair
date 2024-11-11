n=int(input())
s=input()
l=[input().split("->") for i in range(n)]
if l[-1][1]==s:
    print("home")
else:
    print("contest")
    