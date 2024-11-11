a,v=map(int,input().split())
b,w=map(int,input().split())
T=int(input())
if abs(a-b)<T*(v-w):
    print("YES")
else:
    print("NO")

