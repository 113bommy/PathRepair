a,v = map(int,input().split())
b,w = map(int,input().split())
t = int(input())
if abs(a-v) <= (v-w)*t:
    print("YES")
else:
    print("NO")