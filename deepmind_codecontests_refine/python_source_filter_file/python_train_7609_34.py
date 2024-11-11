N = int(input())
L = list(map(int,input().rsplit()))
print(max(L)-min(L)-N)