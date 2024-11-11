a = int(input())
b = int(input())
c = int(input())
if min(a,b,c)==c:
    print(c+1)
else:
    print(max(a,b)-c+min(a,b)+1)
