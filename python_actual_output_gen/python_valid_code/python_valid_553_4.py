a = int(input())
for i in range(a):
    m,s = input().split()
    m = int(m)
    s = int(s)
    print(m/(s//2+1))