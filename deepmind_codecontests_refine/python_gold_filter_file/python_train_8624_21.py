import sys
input = sys.stdin.readline
n=int(input())
s=input()
def solve():
    for i in range(1,n):
        if (ans[i]=="S" and s[i]=="o") or (ans[i]=="W" and s[i]=="x"):
            ans[i+1]=ans[i-1]
        else:
            if ans[i-1]=="S":
                ans[i+1]="W"
            else:
                ans[i+1]="S"

        if (ans[0]=="S" and s[0]=="o") or (ans[0]=="W" and s[0]=="x"):
            sl=ans[1]
        else:
            if ans[1]=="S":
                sl="W"
            else:
                sl="S"
    if ans[0]==ans[-1] and sl==ans[n-1]:
        return True
    else:
        return False

ans=[0]*(n+1)

for i in ["S","W"]:
    for j in ["S","W"]:
        ans[0]=i
        ans[1]=j
        if solve():
            print("".join(ans[:-1]))
            exit()
print(-1)
