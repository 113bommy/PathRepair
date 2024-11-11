ans=0
for _ in range(int(input())):
    ans^=int(((9+8*int(input()))**0.5-2)//2)
print(['YES', 'NO'][ans>0])