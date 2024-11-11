a = int(input())
for i in range(a):
    m,s = input().split()
    m = int(m)
    s = int(s)
    print(int(s/(m//2+1)))